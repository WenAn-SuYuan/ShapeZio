#include "scissor.h"
#include"GlobalArray.h"
#include<QDebug>
#include<QTimer>
#include"leftcircle.h"
#include"rightcircle.h"

int Scissor::temVelocity = 0;
bool Scissor::temHaveAdvanced = false;

Scissor::Scissor(QWidget *parent)
    : QLabel{parent}
{
    //qDebug() << "切割机调用构造";
    QPixmap pix;
    if(direction == 0){
        pix = scaleImage(":/machine_and_pic /PictureSource/UpScissor.png", QSize(50, 50));
        //qDebug() << "direction = 0切割机构造自身";
    } else if(direction == 1){
        pix = scaleImage(":/machine_and_pic /PictureSource/DownScissor.png", QSize(50, 50));
    } else if (direction == 2){
        pix = scaleImage(":/machine_and_pic /PictureSource/LeftScissor.png", QSize(50, 50));
    } else if(direction == 3){
        pix = scaleImage(":/machine_and_pic /PictureSource/RightScissor.png", QSize(50, 50));
    }
    setPixmap(pix);

    QTimer *timer = new QTimer;
    connect(timer,&QTimer::timeout, this, [=](){

        if(!work && ScissorType == 0 && need){
            //qDebug() << "进入切割过程";
            if(scissorJudge(x, y, direction) == 0){
                work = true;
            } else if(scissorJudge(x, y, direction) == 1){

                if(direction == 0){
                    setUpRightCircle(x+1, y-1);

                } else if(direction == 1){
                    setUpRightCircle(x-1, y+1);

                } else if(direction == 2){
                    setUpRightCircle(x-1, y-1);

                } else if(direction == 3){
                    setUpRightCircle(x+1, y+1);
                }

                work = true;
            } else if(scissorJudge(x, y ,direction) == 2){
                if(direction == 0){
                    setUpLeftCircle(x, y-1);

                } else if(direction == 1){
                    setUpLeftCircle(x, y+1);

                } else if(direction == 2){
                    setUpLeftCircle(x-1, y);

                } else if(direction == 3){
                    setUpLeftCircle(x+1, y);
                }


                work = true;


            } else if(scissorJudge(x, y ,direction) == 3){
                if(direction == 0){
                    setUpLeftCircle(x, y-1);
                    setUpRightCircle(x+1, y-1);

                } else if(direction == 1){
                    setUpLeftCircle(x, y+1);
                    setUpRightCircle(x-1, y+1);

                } else if(direction == 2){
                    setUpLeftCircle(x-1, y);
                    setUpRightCircle(x-1, y-1);

                } else if(direction == 3){
                    setUpLeftCircle(x+1, y);
                    setUpRightCircle(x+1, y+1);
                }

                work = true;

            }
        }
    });
    timer->start(2000 - temVelocity);








}
QPixmap Scissor::scaleImage(const QString &filePath, const QSize &newSize) {
    QImage image(filePath);
    //检查图片是否加载成功
    if (image.isNull()) {
        // 加载失败处理
        qDebug() << "缩放失败" << Qt::endl;
        return QPixmap();
    }

    //等比例缩放图片
    QPixmap pixmap = QPixmap::fromImage(image).scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    return pixmap;
}
bool Scissor::event(QEvent *e){  ///仅当点击产生左半边图形的那个切割机部分使用，点击右半边无反应
    if(ScissorType == 1){
        return QLabel::event(e);
    }
    if(e->type() == QEvent::MouseButtonPress){
        ++direction;

        QPixmap pix;
        if(direction == 0){ ////其实这里没有用处 为了代码全面一点，因为没有正数+1后为0
            pix = scaleImage(":/machine_and_pic /PictureSource/UpScissor.png", QSize(50, 50));
            setPixmap(pix);
        } else if(direction == 1){

            map[x+1][y]->scissor->hide();
            map[x+1][y]->scissor->need = false;
            map[x+1][y]->scissor->ScissorType = -1;

            pix = scaleImage(":/machine_and_pic /PictureSource/DownScissor.png", QSize(50, 50));
            setUpOne(x-1, y);
            setPixmap(pix);
            map[x-1][y]->scissor->setPixmap(pix);
            map[x-1][y]->scissor->direction = 1;


        } else if (direction == 2){
            map[x-1][y]->scissor->hide();
            map[x-1][y]->scissor->need = false;
            map[x-1][y]->scissor->ScissorType = -1;

            pix = scaleImage(":/machine_and_pic /PictureSource/LeftScissor.png", QSize(50, 50));
            setUpOne(x, y-1);
            setPixmap(pix);
            map[x][y-1]->scissor->setPixmap(pix);
            map[x][y-1]->scissor->direction = 2;
        } else if(direction == 3){
            map[x][y-1]->scissor->hide();
            map[x][y-1]->scissor->need = false;
            map[x][y-1]->scissor->ScissorType = -1;

            pix = scaleImage(":/machine_and_pic /PictureSource/RightScissor.png", QSize(50, 50));
            setUpOne(x, y+1);
            setPixmap(pix);
            map[x][y+1]->scissor->setPixmap(pix);
            map[x][y+1]->scissor->direction = 3;
        } else {
            this->hide();
            need = false;
            ScissorType = -1;

            map[x][y+1]->scissor->hide();
            map[x][y+1]->scissor->need = false;
            map[x][y+1]->scissor->ScissorType = -1;

            return true;
        }

    }
    return QLabel::event(e);

}
void Scissor::setUpOne(int m, int n){
    map[m][n]->scissor = new Scissor(this->parentWidget());
    map[m][n]->scissor->setGeometry(35 + 50 * m, 35 + 50 * n, 50, 50);
    map[m][n]->scissor->show();
    map[m][n]->scissor->setParent(this->parentWidget());
    map[m][n]->scissor->x = m, map[m][n]->scissor->y = n;
    map[m][n]->scissor->ScissorType = 1;

    if(map[m][n]->belt != nullptr){
        map[m][n]->belt->hide();
        map[m][n]->belt->need = false;
    } else if(map[m][n]->shovel != nullptr){
        map[m][n]->shovel->hide();
        map[m][n]->shovel->need = false;
    } else if(map[m][n]->trashbin != nullptr){
        map[m][n]->trashbin->hide();
        map[m][n]->trashbin->need = false;
    }


}
int Scissor::scissorJudge(int m, int n, int direc){
    //qDebug() << "调用scissorJudge函数";

    if(direc == 0){
        if(map[m][n-1]->trashbin != nullptr && map[m][n-1]->trashbin->need
            && map[m+1][n-1]->trashbin != nullptr && map[m+1][n-1]->trashbin->need){
            // qDebug() << "调用scissorJudge函数 返回0";
            return 0;
        } else if(map[m][n-1]->trashbin != nullptr && map[m][n-1]->trashbin->need
                   && map[m+1][n-1]->belt != nullptr && map[m+1][n-1]->belt->need && !(map[m+1][n-1]->takenUp)){
            // qDebug() << "调用scissorJudge函数 返回1";
            return 1;
        } else if(map[m][n-1]->belt != nullptr && map[m][n-1]->belt->need && !(map[m][n-1]->takenUp)
                   && map[m+1][n-1]->trashbin != nullptr && map[m+1][n-1]->trashbin->need){
            // qDebug() << "调用scissorJudge函数 返回2";
            return 2;
        } else if(map[m][n-1]->belt != nullptr && map[m][n-1]->belt->need && !(map[m][n-1]->takenUp)
                   && map[m+1][n-1]->belt != nullptr && map[m+1][n-1]->belt->need && !(map[m+1][n-1]->takenUp)){
            //qDebug() << "调用scissorJudge函数 返回3";
            return 3;
        } else {
            //qDebug() << "调用scissorJudge函数 返回-1";
            return -1;
        }
    } else if(direc == 1){
        if(trashbinCanUse(m, n+1) && trashbinCanUse(m-1, n+1)){
            return 0;
        } else if(trashbinCanUse(m, n+1) && beltCanUse(m-1, n+1)){
            return 1;
        } else if(beltCanUse(m, n+1) && trashbinCanUse(m-1, n+1)){
            return 2;
        } else if(beltCanUse(m, n+1) && beltCanUse(m-1, n+1)){
            return 3;
        } else {
            return -1;
        }

    } else if(direc == 2){
        if(trashbinCanUse(m-1, n) && trashbinCanUse(m-1, n-1)){
            return 0;
        } else if(trashbinCanUse(m-1, n) && beltCanUse(m-1, n-1)){
            return 1;
        } else if(beltCanUse(m-1, n) && trashbinCanUse(m-1, n-1)){
            return 2;
        } else if(beltCanUse(m-1, n) && beltCanUse(m-1, n-1)){
            return 3;
        } else {
            return -1;
        }
    } else if(direc == 3){
        if(trashbinCanUse(m+1, n) && trashbinCanUse(m+1, n+1)){
            return 0;
        } else if(trashbinCanUse(m+1, n) && beltCanUse(m+1, n+1)){
            return 1;
        } else if(beltCanUse(m+1, n) && trashbinCanUse(m+1, n+1)){
            return 2;
        } else if(beltCanUse(m+1, n) && beltCanUse(m+1, n+1)){
            return 3;
        } else {
            return -1;
        }
    }
    return -1;



}
void Scissor::setUpLeftCircle(int m, int n){
    LeftCircle *lcir = new LeftCircle(parentWidget());
    lcir->setParent(parentWidget());
    lcir->show();
    lcir->x = m, lcir->y = n;
    lcir->setGeometry(35 + 50 * lcir->x, 35 + 50 * lcir->y, 50, 50);
    map[lcir->x][lcir->y]->takenUp = true;
}
void Scissor::setUpRightCircle(int m, int n){
    RightCircle *rcir = new RightCircle(parentWidget());
    rcir->setParent(parentWidget());
    rcir->show();
    rcir->x = m, rcir->y = n;
    rcir->setGeometry(35 + 50 * rcir->x, 35 + 50 * rcir->y, 50, 50);
    map[rcir->x][rcir->y]->takenUp = true;
}







#include "shovel.h"
#include<QPixmap>
#include<QTimer>
#include"GlobalArray.h"
#include"circle.h"
#include"triangle.h"

int Shovel::temVelocity = 0;
bool Shovel::temHaveAdvanced = false;

Shovel::Shovel(QWidget *parent)
    : QLabel{parent}
{
    QPixmap pix;
    if(direction == 0){
        pix = scaleImage(":/machine_and_pic /PictureSource/UpShovel.png", QSize(50, 50));
    } else if(direction == 1){
        pix = scaleImage(":/machine_and_pic /PictureSource/DownShovel.png", QSize(50, 50));
    } else if (direction == 2){
        pix = scaleImage(":/machine_and_pic /PictureSource/LeftShovel.png", QSize(50, 50));
    } else if(direction == 3){
        pix = scaleImage(":/machine_and_pic /PictureSource/RightShovel.png", QSize(50, 50));
    }

    setPixmap(pix);
    // if(map[x][y]->haveCircle){
    //     qDebug() << "成功";

    // } else {
    //     qDebug() << "成功2";
    // }
    QTimer * timer = new QTimer;
    connect(timer, &QTimer::timeout, this, [=](){      //开采器部分 若旁边有传送带，则创建相应对象
        if(need){
            if(map[x][y]->haveCircle){
                if(direction == 0 && y > 0 && map[x][y-1]->belt != nullptr && !(map[x][y-1]->takenUp)){
                    Circle *cir = new Circle(this->parentWidget());
                    cir->setGeometry(35 + 50 * x, 35 + 50 * (y - 1), 50, 50);
                    cir->show();
                    cir->setParent(parentWidget());
                    map[x][y-1]->takenUp = true;
                    cir->x = x, cir->y = y-1;
                    //qDebug() << "创建一个圆形";

                } else if(direction == 1 && y < 9 && map[x][y+1]->belt != nullptr && !(map[x][y+1]->takenUp)){
                    Circle *cir = new Circle(this->parentWidget());
                    cir->setGeometry(35 + 50 * x, 35 + 50 * (y + 1), 50, 50);
                    cir->show();
                    cir->setParent(parentWidget());
                    map[x][y+1]->takenUp = true;
                    cir->x = x, cir->y = y+1;

                } else if(direction == 2 && x > 0 && map[x-1][y]->belt != nullptr && !(map[x-1][y]->takenUp)){
                    Circle *cir = new Circle(this->parentWidget());
                    cir->setGeometry(35 + 50 * (x - 1), 35 + 50 * y, 50, 50);
                    cir->show();
                    cir->setParent(parentWidget());
                    map[x-1][y]->takenUp = true;
                    cir->x = x - 1, cir->y = y;

                } else if(direction == 3 && x < 14 && map[x+1][y]->belt != nullptr && !(map[x+1][y]->takenUp)){
                    Circle *cir = new Circle(this->parentWidget());
                    cir->setGeometry(35 + 50 * (x + 1), 35 + 50 * y, 50, 50);
                    cir->show();
                    cir->setParent(parentWidget());
                    map[x+1][y]->takenUp = true;
                    cir->x = x + 1, cir->y = y;

                }
            } else if(map[x][y]->haveTriangle){
                if(direction == 0 && y > 0 && map[x][y-1]->belt != nullptr && !(map[x][y-1]->takenUp)){
                    Triangle *tri = new Triangle(this->parentWidget());
                    tri->setGeometry(35 + 50 * x, 35 + 50 * (y - 1), 50, 50);
                    tri->show();
                    tri->setParent(parentWidget());
                    map[x][y-1]->takenUp = true;
                    tri->x = x, tri->y = y-1;


                } else if(direction == 1 && y < 9 && map[x][y+1]->belt != nullptr && !(map[x][y+1]->takenUp)){
                    Triangle *tri = new Triangle(this->parentWidget());
                    tri->setGeometry(35 + 50 * x, 35 + 50 * (y + 1), 50, 50);
                    tri->show();
                    tri->setParent(parentWidget());
                    map[x][y+1]->takenUp = true;
                    tri->x = x, tri->y = y+1;

                } else if(direction == 2 && x > 0 && map[x-1][y]->belt != nullptr && !(map[x-1][y]->takenUp)){
                    Triangle *tri = new Triangle(this->parentWidget());
                    tri->setGeometry(35 + 50 * (x - 1), 35 + 50 * y, 50, 50);
                    tri->show();
                    tri->setParent(parentWidget());
                    map[x-1][y]->takenUp = true;
                    tri->x = x - 1, tri->y = y;

                } else if(direction == 3 && x < 14 && map[x+1][y]->belt != nullptr && !(map[x+1][y]->takenUp)){
                    Triangle *tri = new Triangle(this->parentWidget());
                    tri->setGeometry(35 + 50 * (x + 1), 35 + 50 * y, 50, 50);
                    tri->show();
                    tri->setParent(parentWidget());
                    map[x+1][y]->takenUp = true;
                    tri->x = x + 1, tri->y = y;

                }


            } else {

            }



        }
    });
    timer->start(2000 - temVelocity);

}
QPixmap Shovel::scaleImage(const QString &filePath, const QSize &newSize) {
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
bool Shovel::event(QEvent *e){
    if(e->type() == QEvent::MouseButtonPress){
        ++direction;

        QPixmap pix;
        if(direction == 0){
            pix = scaleImage(":/machine_and_pic /PictureSource/UpShovel.png", QSize(50, 50));
        } else if(direction == 1){
            pix = scaleImage(":/machine_and_pic /PictureSource/DownShovel.png", QSize(50, 50));
        } else if (direction == 2){
            pix = scaleImage(":/machine_and_pic /PictureSource/LeftShovel.png", QSize(50, 50));
        } else if(direction == 3){
            pix = scaleImage(":/machine_and_pic /PictureSource/RightShovel.png", QSize(50, 50));
        } else {
            this->hide();
            need = false;
            return true;
        }

        setPixmap(pix);
    }




    return QLabel::event(e);

}


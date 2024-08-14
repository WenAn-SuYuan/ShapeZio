#include "triangle.h"
#include<QPixmap>
#include"GlobalArray.h"
#include<QTimer>

int Triangle::numInDestination = 0;

Triangle::Triangle(QWidget *parent)
    : QLabel{parent}
{
    QPixmap pix = scaleImage(":/machine_and_pic /PictureSource/triangle.png", QSize(50, 50));
    setPixmap(pix);

    QTimer * timer = new QTimer;
    connect(timer, &QTimer::timeout, this, [=](){

        if((map[x][y]->belt != nullptr) && (map[x][y]->belt->need) && need){
            if(map[x][y]->belt->direction == 0 && y > 0){///向上传送

                // map[x][y]->takenUp = false;
                // moveHere(x, y-1);

                if(moveHere(x, y-1)){
                    map[x][y+1]->takenUp = false;
                }

            } else if(map[x][y]->belt->direction == 1 && y < 9){

                // map[x][y]->takenUp = false;
                // moveHere(x, y+1);

                //qDebug() << "进入向下移动函数" ;
                if(moveHere(x, y+1)){
                    map[x][y-1]->takenUp = false;
                }

            } else if(map[x][y]->belt->direction == 2 && x > 0){

                // map[x][y]->takenUp = false;
                // moveHere(x-1, y);
                if(moveHere(x-1, y)){
                    map[x+1][y]->takenUp = false;
                }

            } else if(map[x][y]->belt->direction == 3 && x < 14){

                // map[x][y]->takenUp = false;
                // moveHere(x+1, y);
                if(moveHere(x+1, y)){
                    map[x-1][y]->takenUp = false;
                }

            }
        }

    });
    timer->start(2000 - Belt::temVelocity);





}
QPixmap Triangle::scaleImage(const QString &filePath, const QSize &newSize) {
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
bool Triangle::moveHere(int m, int n){
    if(map[m][n]->belt != nullptr && map[m][n]->belt->need && !(map[m][n]->takenUp)){
        move(35 + 50 * m, 35 + 50 * n);
        x = m, y = n;
        map[m][n]->takenUp = true;
        return true;

    } else if(map[m][n]->trashbin != nullptr && (map[m][n]->trashbin->need)){
        hide();
        need = false;
        x = m, y = n;
        return true;
    } else if(map[m][n]->destination){
        hide();
        need = false;
        x = m, y = n;
        numInDestination++;
        return true;
    }

    return false;
}
bool Triangle::event(QEvent *e){
    if(e->type() == QEvent::MouseButtonPress){

        for(int col = -1; col <= 1; ++col){
            for(int row = -1; row <= 1; ++row){
                if((x + col >= 0) && (x + col <= 14) && (y + row >= 0) && (y + col <= 9)
                    && map[x + col][y + row]->bomb != nullptr && map[x + col][y + row]->bomb->need){
                    hide();
                    need = false;
                    map[x][y]->takenUp = false;
                    return true;
                }
            }

        }


    }





    return QLabel::event(e);

}



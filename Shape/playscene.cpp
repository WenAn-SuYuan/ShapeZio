#include "playscene.h"
#include<QPainter>
#include"GlobalArray.h"
#include<QString>
#include"leftcircle.h"
#include"circle.h"
#include"triangle.h"
#include<QTimer>
#include"task.h"
#include<QPushButton>
#include"shop.h"


playScene::playScene(QWidget *parent)
    : QMainWindow{parent}
{
    setFixedSize(1000, 700);
    setWindowTitle("ShapeZio");

    //此处显示地图
    for(int i = 0; i < 15; ++i){
        for(int j = 0; j < 10; ++j){
            MapLabel *board = new MapLabel;
            map[i][j] = board;
            QPixmap pix = scaleImage(":/machine_and_pic /PictureSource/board1.png", QSize(50, 50));
            board->setParent(this);
            board->setPixmap(pix);
            board->setGeometry(0, 0, 50, 50);
            board->move(35 + 50 * i, 35 + 50 * j);
            board->x = i;
            board->y = j;


            if(!Shop::mineralAdvanced){
                if((i == 1 || i == 2) &&(j == 1 || j == 2)){
                    board->haveCircle = true;
                    QPixmap pix1 = scaleImage(":/machine_and_pic /PictureSource/circle.png", QSize(50, 50));
                    board->setPixmap(pix1);

                }  ///圆形矿物开采处的建立

                if((i == 1 || i == 2) && (j == 7 || j == 8)){
                    board->haveTriangle = true;
                    QPixmap pix1 = scaleImage(":/machine_and_pic /PictureSource/triangle.png", QSize(50, 50));
                    board->setPixmap(pix1);
                } ///三角形矿物开采处的建立
            } else {
                if((i == 1 || i == 2 || i == 3) &&(j == 1 || j == 2 || j == 3)){
                    board->haveCircle = true;
                    QPixmap pix1 = scaleImage(":/machine_and_pic /PictureSource/circle.png", QSize(50, 50));
                    board->setPixmap(pix1);

                }  ///圆形矿物开采处的建立(强化后）

                if((i == 1 || i == 2 || i == 3) && (j == 6 || j == 7 || j == 8)){
                    board->haveTriangle = true;
                    QPixmap pix1 = scaleImage(":/machine_and_pic /PictureSource/triangle.png", QSize(50, 50));
                    board->setPixmap(pix1);
                } ///三角形矿物开采处的建立（强化后）
            }



            if(!Shop::destinationAdvanced){
                if((i == 12 || i == 13) && (j == 1 || j == 2)){
                    QPixmap pix1 = scaleImage(":/machine_and_pic /PictureSource/destination.png", QSize(50, 50));
                    board->setPixmap(pix1);
                    board->destination = true;
                }///交付中心的建立
            } else {
                if((i == 11 || i == 12 || i == 13) && (j == 1 || j == 2 || j == 3)){
                    QPixmap pix1 = scaleImage(":/machine_and_pic /PictureSource/destination.png", QSize(50, 50));
                    board->setPixmap(pix1);
                    board->destination = true;
                }///交付中心的建立（强化后）
            }







        }
    }

    QLabel *leftCircleNum = new QLabel(this);
    leftCircleNum->setParent(this);
    leftCircleNum->setGeometry(800, 60, 200, 100);

    QLabel *circleNum = new QLabel(this);
    circleNum->setParent(this);
    circleNum->setGeometry(800, 100, 200, 100);

    QLabel *triangleNum = new QLabel(this);
    triangleNum->setParent(this);
    triangleNum->setGeometry(800, 140, 200, 100);  ///上面这三个：显示已交付的图形个数

    QLabel *firsttask = new QLabel(this);
    firsttask->setParent(this);
    firsttask->setGeometry(800, 300, 200, 100);

    QLabel *secondtask = new QLabel(this);
    secondtask->setParent(this);
    secondtask->setGeometry(800, 400, 200, 100);

    QLabel *thirdtask = new QLabel(this);
    thirdtask->setParent(this);
    thirdtask->setGeometry(800, 500, 200, 100);///上面这三个：显示任务


    bool firstComplete = false;
    bool secondComplete = false;
    bool thirdComplete = false;
    //此处显示交付的左半圆数量
    QTimer *timer = new QTimer;
    connect(timer, &QTimer::timeout, this, [=]()mutable{
        QString numStringLeftCircle = QString::number(LeftCircle::numInDestination);
        QString goalStringLeftCircle = "已交付的左半圆数量：" + numStringLeftCircle;
        leftCircleNum->setText(goalStringLeftCircle);

        QString numStringCircle = QString::number(Circle::numInDestination);
        QString goalStringCircle = "已交付的圆数量：" + numStringCircle;
        circleNum->setText(goalStringCircle);

        QString numStringTriangle = QString::number(Triangle::numInDestination);
        QString goalStringTriangle = "已交付的三角形数量：" + numStringTriangle;
        triangleNum->setText(goalStringTriangle);                 ///上面这三个：交付图形个数的实现

        if(Circle::numInDestination >= 20){
            firsttask->setText("任务一：交付20个圆形矿物\n(已完成)");
        } else {
            firsttask->setText("任务一：交付20个圆形矿物");
        }

        if(Triangle::numInDestination >= 30){
            secondtask->setText("任务二：交付30个三角形矿物\n(已完成)");
        } else {
            secondtask->setText("任务二：交付30个三角形矿物");
        }

        if(LeftCircle::numInDestination >= 50){
            thirdtask->setText("任务三：交付50个左半圆形矿物\n(已完成)");
        } else {
            thirdtask->setText("任务三：交付50个左半圆形矿物");
        }                                                     ///上面这三个：任务的实现



        if((Circle::numInDestination >= 20 && !firstComplete) || (Triangle::numInDestination >= 30 && !secondComplete)
            || (LeftCircle::numInDestination >= 50 && !thirdComplete)){
            Task *task = new Task;
            task->show();
            if(Circle::numInDestination >= 20 && !firstComplete){
                firstComplete= true;
            } else if(Triangle::numInDestination >= 30 && !secondComplete){
                secondComplete = true;
            } else {
                thirdComplete = true;
            }

            if(!Shop::moneyAdvanced){  ////完成任务时构建升级界面,并获得金币(下面强化后）
                money += 10;
            } else {
                money += 20;
            }
        }



    });
    timer->start(100);



}

QPixmap scaleImage(const QString &filePath, const QSize &newSize) {
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


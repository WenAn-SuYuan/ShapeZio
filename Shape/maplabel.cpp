#include "maplabel.h"
#include<QDebug>
#include<QPushButton>
#include<QVBoxLayout>
#include<QTimer>
#include"circle.h"
#include"GlobalArray.h"
#include<QJsonObject>

MapLabel::MapLabel(QWidget *parent)
    : QLabel{parent}
{}



bool MapLabel::event(QEvent * e){
    if(e->type() == QEvent::MouseButtonPress){
        //弹出选择创建目标的对话框
        QWidget * wi = new QWidget();
        QVBoxLayout *lay = new QVBoxLayout(wi);
        wi->setLayout(lay);
        wi->setGeometry(500, 200, 500, 500);
        wi->show();

        //传送带的建立
        QPushButton *btnBelt = new QPushButton("建立传送带");
        lay->addWidget(btnBelt);
        connect(btnBelt, &QPushButton::clicked, this, [=](){
            belt = new Belt(this->parentWidget());
            belt->setGeometry(35 + 50 * this->x, 35 + 50 * this->y, 50, 50);
            belt->show();
            belt->x = this->x, belt->y = this->y;
            wi->close();
        });


        //开采器建立
        QPushButton *btnShovel = new QPushButton("建立开采器");
        lay->addWidget(btnShovel);
        connect(btnShovel, &QPushButton::clicked, this, [=](){
            shovel = new Shovel(this->parentWidget());
            shovel->setGeometry(35 + 50 * this->x,35 + 50 * this->y, 50, 50);
            shovel->show();
            shovel->x = this->x, shovel->y = this->y;
            wi->close();
        });

        //垃圾桶建立
        QPushButton *btnTrashbin = new QPushButton("建立垃圾桶");
        lay->addWidget(btnTrashbin);
        connect(btnTrashbin, &QPushButton::clicked, this, [=](){
            trashbin = new Trashbin(this->parentWidget());
            trashbin->setGeometry(35 + 50 * this->x,35 + 50 * this->y, 50, 50);
            trashbin->show();
            trashbin->x = this->x, trashbin->y = this->y;
            wi->close();
        });

        //切割机建立
        QPushButton *btnScissor = new QPushButton("建立切割机");
        lay->addWidget(btnScissor);
        connect(btnScissor, &QPushButton::clicked, this, [=](){
            if(x > 0 && x < 14 && y > 0 && y < 9){
                //qDebug() << "地图调用切割机构造";
                scissor = new Scissor(this->parentWidget());
                scissor->setGeometry(35 + 50 * this->x,35 + 50 * this->y, 50, 50);
                scissor->show();
                scissor->x = this->x, scissor->y = this->y;
                scissor->ScissorType = 0;

                map[x+1][y]->scissor = new Scissor(this->parentWidget());
                map[x+1][y]->scissor->setGeometry(35 + 50 * (this->x + 1),35 + 50 * this->y, 50, 50);
                map[x+1][y]->scissor->show();
                map[x+1][y]->scissor->x = (this->x + 1), map[x+1][y]->scissor->y = this->y;
                map[x+1][y]->scissor->ScissorType = 1;


            }
            wi->close();
        });
        QPushButton *btnBomb = new QPushButton("建立炸弹");
        lay->addWidget(btnBomb);
        connect(btnBomb, &QPushButton::clicked, this, [=](){
            bomb = new Bomb(this->parentWidget());
            bomb->setGeometry(35 + 50 * this->x,35 + 50 * this->y, 50, 50);
            bomb->show();
            bomb->x = this->x, bomb->y = this->y;
            wi->close();
        });





        return true;
    }
    return QLabel::event(e);
}
// void MapLabel::read(const QJsonObject &json)
// {


// }

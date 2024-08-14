#include "shop.h"
#include<QPushButton>
#include"GlobalArray.h"
#include<QLabel>
#include<QTimer>


bool Shop::mineralAdvanced = false;
bool Shop::destinationAdvanced = false;
bool Shop::moneyAdvanced = false;

Shop::Shop(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(1000, 950);

    QPushButton *btnMineral = new QPushButton(this);
    QPushButton *btnDestination = new QPushButton(this);
    QPushButton *btnMoney = new QPushButton(this);
    btnMineral->setParent(this);
    btnDestination->setParent(this);
    btnMoney->setParent(this);


    btnMineral->setGeometry(400, 100, 200 ,100);
    btnDestination->setGeometry(400, 300, 200, 100);
    btnMoney->setGeometry(400, 500, 200, 100);

    QTimer *timerOfAdvance = new QTimer;
    connect(timerOfAdvance, &QTimer::timeout, this, [=](){
        if(mineralAdvanced){
            btnMineral->setText("开采物地格数量已满级");
        } else {
            btnMineral->setText("强化开采物地格数量");
        }


        if(destinationAdvanced){
            btnDestination->setText("交付中心地格数量已满级");
        } else {
            btnDestination->setText("强化交付中心地格数量");
        }

        if(moneyAdvanced){
            btnMoney->setText("完成任务所获的金币数量已满级");
        } else {
            btnMoney->setText("强化完成任务获得的金币数量");
        }
    });
    timerOfAdvance->start(100);




    connect(btnMineral, &QPushButton::clicked, this, [=](){
        if(money >= 10 && !mineralAdvanced){
            money -= 10;
            mineralAdvanced = true;
        }
    });
    connect(btnDestination, &QPushButton::clicked, this, [=](){
        if(money >= 10 && !destinationAdvanced){
            money -= 10;
            destinationAdvanced = true;
        }
    });
    connect(btnMoney, &QPushButton::clicked, this, [=](){
        if(money >= 10 && !moneyAdvanced){
            money -= 10;
            moneyAdvanced = true;
        }
    });

    QLabel *moneyAmount = new QLabel(this); ////显示金币数量
    moneyAmount->setParent(this);
    moneyAmount->show();
    moneyAmount->setGeometry(700, 100, 100, 50);
    QTimer *timer = new QTimer;
    connect(timer, &QTimer::timeout, this, [=](){
        QString moneyString = QString::number(money);
        QString realString = "金币数量：" + moneyString;
        moneyAmount->setText(realString);
    });
    timer->start(100);








}

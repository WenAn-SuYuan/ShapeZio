#include "task.h"
#include"belt.h"
#include"shovel.h"
#include"scissor.h"
#include<QPushButton>
#include<QLabel>
Task::Task(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(950, 700);
    setWindowTitle("升级机器");
    if(!Belt::temHaveAdvanced){
        QPushButton *btnBelt = new QPushButton(this);
        btnBelt->setParent(this);
        btnBelt->setText("升级传送带");
        btnBelt->setGeometry(200, 300, 200, 100);
        btnBelt->show();
        connect(btnBelt, &QPushButton::clicked, this, [=](){
            Belt::temVelocity = 700;
            Belt::temHaveAdvanced = true;
            close();
        });

    } else {
        QLabel *labelBelt = new QLabel(this);
        labelBelt->setText("传送带已满级");
        labelBelt->show();
        labelBelt->setParent(this);
        labelBelt->setGeometry(200, 300, 200, 100);
    }

    if(!Shovel::temHaveAdvanced){
        QPushButton *btnShovel = new QPushButton(this);
        btnShovel->setParent(this);
        btnShovel->setText("升级开采器");
        btnShovel->setGeometry(450, 300, 200, 100);
        btnShovel->show();
        connect(btnShovel, &QPushButton::clicked, this, [=](){
            Shovel::temVelocity = 700;
            Shovel::temHaveAdvanced = true;
            close();
        });
    } else {
        QLabel *labelShovel = new QLabel(this);
        labelShovel->setText("开采器已满级");
        labelShovel->show();
        labelShovel->setParent(this);
        labelShovel->setGeometry(450, 300, 200,100);
    }

    if(!Scissor::temHaveAdvanced){
        QPushButton *btnScissor = new QPushButton(this);
        btnScissor->setParent(this);
        btnScissor->setText("升级切割机");
        btnScissor->setGeometry(700, 300, 200, 100);
        btnScissor->show();
        connect(btnScissor, &QPushButton::clicked, this, [=](){
            Scissor::temVelocity = 700;
            Scissor::temHaveAdvanced = true;
            close();
        });

    } else {
        QLabel *labelScissor = new QLabel(this);
        labelScissor->setText("切割机已满级");
        labelScissor->show();
        labelScissor->setParent(this);
        labelScissor->setGeometry(700, 400, 200, 100);
    }

}

#include "mainscene.h"
#include "ui_mainscene.h"
#include<QMenuBar>
#include"startbutton.h"
#include"shop.h"
#include"circle.h"
#include"leftcircle.h"
#include"triangle.h"

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    setFixedSize(1000, 700);
    setWindowIcon(QIcon(":/res/circle.png"));
    setWindowTitle("ShapeZio");
    ui->menubar->setNativeMenuBar(false);


    //退出按钮
    connect(ui->actionquit, &QAction::triggered, this, [=](){
        this->close();
    });

    startButton * btn = new startButton(this);
    btn->setParent(this);
    //btn->move(400, 550);
    btn->show();


    //点击start进入游玩界面
    //playscene = new playScene;

    ///返回主界面按钮的实现
    connect(btn, &QPushButton::clicked, this,[=](){
        playscene = new playScene;
        this->hide();
        playscene->show();
        QPushButton *btnback = new QPushButton(playscene);
        //btnback->parent = playscene;
        btnback->setParent(playscene);
        btnback->setGeometry(800, 600, 100, 100);
        btnback->setText("返回主界面");
        btnback->show();
        connect(btnback, &QPushButton::clicked, playscene, [=](){
            playscene->close();
            Circle::numInDestination = 0;
            LeftCircle::numInDestination = 0;
            Triangle::numInDestination = 0;
            Belt::temHaveAdvanced = false;
            Shovel::temHaveAdvanced = false;
            Scissor::temHaveAdvanced = false;
            delete playscene;
            this->show();
        });

    } );

    QPushButton *btnShop = new QPushButton(this); ///全局强化系统
    btnShop->setParent(this);
    btnShop->setText("商店");
    btnShop->setGeometry(400, 200, 200, 100);
    btnShop->show();
    connect(btnShop, &QPushButton::clicked, this, [=](){
        Shop *shop = new Shop;
        shop->show();
    });





}

MainScene::~MainScene()
{
    delete ui;
}

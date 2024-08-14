#ifndef MAPLABEL_H
#define MAPLABEL_H

#include <QLabel>
#include<QEvent>
#include"belt.h"
#include"shovel.h"
#include"trashbin.h"
#include"scissor.h"
#include"bomb.h"

class MapLabel : public QLabel
{
    Q_OBJECT
public:


    Belt* belt = nullptr;
    Shovel* shovel = nullptr;
    Trashbin *trashbin = nullptr;
    Scissor *scissor = nullptr;
    Bomb *bomb = nullptr;



    int x;
    int y;
    bool takenUp = false;    /// 旁边位置是否已被其他图形占用

    bool haveCircle = false;
    bool haveTriangle = false;

    bool destination = false; ///是否为交付中心标志


    explicit MapLabel(QWidget *parent = nullptr);


    bool event(QEvent *e);

    // void read(const QJsonObject &json);




signals:
};

#endif // MAPLABEL_H

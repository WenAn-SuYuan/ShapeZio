#ifndef SHOVEL_H
#define SHOVEL_H

#include <QLabel>
#include<QEvent>


class Shovel : public QLabel
{
    Q_OBJECT
public:
    int direction = 0; //表示方向，0 1 2 3 分别 上下左右
    int x;
    int y;

    bool need = true;

    static int temVelocity;
    static bool temHaveAdvanced;






    explicit Shovel(QWidget *parent = nullptr);
    QPixmap scaleImage(const QString &filePath, const QSize &newSize);
    bool event(QEvent *e);


signals:
};

#endif // SHOVEL_H

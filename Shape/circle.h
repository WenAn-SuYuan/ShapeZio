#ifndef CIRCLE_H
#define CIRCLE_H

#include <QLabel>
#include<QEvent>

class Circle : public QLabel
{
    Q_OBJECT
public:
    int x;
    int y;

    bool need = true;

    static int numInDestination;

    explicit Circle(QWidget *parent = nullptr);
    QPixmap scaleImage(const QString &filePath, const QSize &newSize) ;
    bool moveHere(int x, int y, int direcUse);   ///作用中包含了修改x y值的部分
    bool event(QEvent *e);


signals:
};

#endif // CIRCLE_H

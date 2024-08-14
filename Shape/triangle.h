#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QLabel>
#include<QEvent>

class Triangle : public QLabel
{
    Q_OBJECT
public:
    int x;
    int y;

    bool need = true;

    static int numInDestination;


    explicit Triangle(QWidget *parent = nullptr);
    QPixmap scaleImage(const QString &filePath, const QSize &newSize) ;
    bool moveHere(int m, int n);   ///作用中包含了修改x y值的部分
    bool event(QEvent *e);

signals:
};

#endif // TRIANGLE_H

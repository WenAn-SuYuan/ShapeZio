#ifndef LEFTCIRCLE_H
#define LEFTCIRCLE_H

#include <QLabel>
#include<QEvent>

class LeftCircle : public QLabel
{
    Q_OBJECT
public:
    int x;
    int y;
    bool need = true;

    static int numInDestination;


    explicit LeftCircle(QWidget *parent = nullptr);
    QPixmap scaleImage(const QString &filePath, const QSize &newSize) ;
    bool moveHere(int m, int n);
    bool event(QEvent *e);

signals:

};


#endif // LEFTCIRCLE_H

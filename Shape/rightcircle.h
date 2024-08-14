#ifndef RIGHTCIRCLE_H
#define RIGHTCIRCLE_H

#include <QLabel>

class RightCircle : public QLabel
{
    Q_OBJECT
public:
    int x;
    int y;

    bool need = true;



    explicit RightCircle(QWidget *parent = nullptr);
    QPixmap scaleImage(const QString &filePath, const QSize &newSize) ;
    bool moveHere(int m, int n);
    bool event(QEvent *e);

signals:
};

#endif // RIGHTCIRCLE_H

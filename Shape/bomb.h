#ifndef BOMB_H
#define BOMB_H

#include <QLabel>

class Bomb : public QLabel
{
    Q_OBJECT
public:
    int x;
    int y;
    bool need = true;




    explicit Bomb(QWidget *parent = nullptr);
    QPixmap scaleImage(const QString &filePath, const QSize &newSize);
    bool event(QEvent *e);


signals:
};

#endif // BOMB_H

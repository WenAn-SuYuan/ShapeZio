#ifndef TRASHBIN_H
#define TRASHBIN_H

#include <QLabel>
#include<QPixmap>
#include<QEvent>

class Trashbin : public QLabel
{
    Q_OBJECT
public:
    int x;
    int y;

    bool need = true;



    explicit Trashbin(QWidget *parent = nullptr);
    QPixmap scaleImage(const QString &filePath, const QSize &newSize);
    bool event(QEvent *e);

signals:
};

#endif // TRASHBIN_H

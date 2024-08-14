#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include"maplabel.h"



class playScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit playScene(QWidget *parent = nullptr);


signals:
};

QPixmap scaleImage(const QString &filePath, const QSize &newSize);

#endif // PLAYSCENE_H

#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include <QPushButton>
#include<QPixmap>

class startButton : public QPushButton
{
    Q_OBJECT
public:
    explicit startButton(QWidget *parent = nullptr);
    QPixmap scaleImage(const QString &filePath, const QSize &newSize);


signals:
};






#endif // STARTBUTTON_H

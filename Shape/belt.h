#ifndef BELT_H
#define BELT_H

#include <QLabel>
#include<QJsonDocument>
#include<QJsonObject>

class Belt : public QLabel
{
    Q_OBJECT
public:

    int direction = 0; //表示方向，0 1 2 3 分别 上下左右
    int x;
    int y;

    static int temVelocity;
    static bool temHaveAdvanced;

    bool need = true;



    explicit Belt(QWidget *parent = nullptr);
    QPixmap scaleImage(const QString &filePath, const QSize &newSize);
    bool event(QEvent *e);
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    // QJsonObject serialize() const ;
    // static Belt* deserialize(const QJsonObject &jsonObject) ;

signals:
};
//QPixmap scaleImage(const QString &filePath, const QSize &newSize);







#endif // BELT_H

#include "belt.h"
#include<QPixmap>
#include<QEvent>
#include<QJsonObject>


int Belt::temVelocity = 0;
bool Belt::temHaveAdvanced = false;


Belt::Belt(QWidget *parent)
    : QLabel{parent}
{
    QPixmap pix;
    if(direction == 0){
        pix = scaleImage(":/machine_and_pic /PictureSource/UpSign.png", QSize(50, 50));
    } else if(direction == 1){
        pix = scaleImage(":/machine_and_pic /PictureSource/DownSign.png", QSize(50, 50));
    } else if (direction == 2){
        pix = scaleImage(":/machine_and_pic /PictureSource/LeftSign.png", QSize(50, 50));
    } else if(direction == 3){
        pix = scaleImage(":/machine_and_pic /PictureSource/RightSign.png", QSize(50, 50));
    }

    setPixmap(pix);

}
QPixmap Belt::scaleImage(const QString &filePath, const QSize &newSize) {
    QImage image(filePath);
    //检查图片是否加载成功
    if (image.isNull()) {
        // 加载失败处理
        qDebug() << "缩放失败" << Qt::endl;
        return QPixmap();
    }

    //等比例缩放图片
    QPixmap pixmap = QPixmap::fromImage(image).scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    return pixmap;
}
bool Belt::event(QEvent *e){
    if(e->type() == QEvent::MouseButtonPress){
        ++direction;
    }
    QPixmap pix;
    if(direction == 0){
        pix = scaleImage(":/machine_and_pic /PictureSource/UpSign.png", QSize(50, 50));
    } else if(direction == 1){
        pix = scaleImage(":/machine_and_pic /PictureSource/DownSign.png", QSize(50, 50));
    } else if (direction == 2){
        pix = scaleImage(":/machine_and_pic /PictureSource/LeftSign.png", QSize(50, 50));
    } else if(direction == 3){
        pix = scaleImage(":/machine_and_pic /PictureSource/RightSign.png", QSize(50, 50));
    } else {
        this->hide();
        need = false;
        return true;
    }

    setPixmap(pix);





    return QLabel::event(e);

}
// void Belt::read(const QJsonObject &json)
// {
//     direction = json["direction"].toInt();
//     x = json["x"].toInt();
//     y = json["y"].toInt();
//     temVelocity = json["temVelocity"].toInt();
//     temHaveAdvanced = json["temHaveAdvanced"].toBool();
//     need = json["need"].toBool();
// };
// void Belt::write(QJsonObject &json) const
// {
//     json["direction"] = direction;
//     json["x"] = x;
//     json["y"] = y;
//     json["temVelocity"] = temVelocity;
//     json["temHaveAdvanced"] = temHaveAdvanced;
//     json["need"] = need;
// }
// QJsonObject Belt::serialize() const {
//     QJsonObject jsonObject;
//     Belt::write(jsonObject);
//     return jsonObject;
// }
// Belt* Belt::deserialize(const QJsonObject &jsonObject) {
//     Belt* obj = new Belt;
//     obj->read(jsonObject);
//     return obj;
// }

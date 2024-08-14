#include "trashbin.h"


Trashbin::Trashbin(QWidget *parent)
    : QLabel{parent}
{
    QPixmap pix;
    pix = scaleImage(":/machine_and_pic /PictureSource/trashbin.png", QSize(50, 50));
    setPixmap(pix);

}




QPixmap Trashbin::scaleImage(const QString &filePath, const QSize &newSize) {
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
bool Trashbin::event(QEvent *e){
    if(e->type() == QEvent::MouseButtonPress){
        this->hide();
        need = false;
        return true;
    }
    return QLabel::event(e);

}



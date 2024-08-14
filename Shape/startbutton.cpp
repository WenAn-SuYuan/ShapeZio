#include "startbutton.h"
#include<QPixmap>
#include<QDebug>



startButton::startButton(QWidget *parent)
    : QPushButton{parent}
{
    QPixmap pix;

    pix = scaleImage(":/machine_and_pic /PictureSource/StartButton.png", QSize(1000, 1000));

    setIcon(pix);
    setIconSize(QSize(100, 100));
    setGeometry(450, 400, 100, 100);


}
QPixmap startButton::scaleImage(const QString &filePath, const QSize &newSize) {
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

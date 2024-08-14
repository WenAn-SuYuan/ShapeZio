#ifndef SCISSOR_H
#define SCISSOR_H

#include <QLabel>
#include<QEvent>
#include<QPixmap>

class Scissor : public QLabel
{
    Q_OBJECT
public:
    int x;
    int y;

    int ScissorType = -1;   ///-1表示无，0为左，1为右
    int direction = 0;
    bool work = true;
    bool need = true;

    static int temVelocity;
    static bool temHaveAdvanced;







    explicit Scissor(QWidget *parent = nullptr);
    QPixmap scaleImage(const QString &filePath, const QSize &newSize);
    bool event(QEvent *e);
    void setUpOne(int m, int n);
    int scissorJudge(int m, int n, int direc);  ///切割机专有判断函数
    ////作用：双垃圾桶，返回0；主位垃圾桶，副位传送带，返回1；主位传送带，副位垃圾桶，返回2；双传送带，返回3；不合条件，返回-1
    void setUpLeftCircle(int m, int n);
    void setUpRightCircle(int m, int n);

signals:
};

#endif // SCISSOR_H

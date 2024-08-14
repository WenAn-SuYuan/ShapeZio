#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include"playscene.h"
#include"ui_mainscene.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainScene;
}
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    playScene * playscene = nullptr;


private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H

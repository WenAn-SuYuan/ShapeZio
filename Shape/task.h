#ifndef TASK_H
#define TASK_H

#include <QWidget>

class Task : public QWidget
{
    Q_OBJECT
public:
    explicit Task(QWidget *parent = nullptr);

signals:
};

#endif // TASK_H

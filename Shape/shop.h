#ifndef SHOP_H
#define SHOP_H

#include <QWidget>

class Shop : public QWidget
{
    Q_OBJECT
public:

    static bool mineralAdvanced;
    static bool destinationAdvanced;
    static bool moneyAdvanced;





    explicit Shop(QWidget *parent = nullptr);

signals:
};

#endif // SHOP_H

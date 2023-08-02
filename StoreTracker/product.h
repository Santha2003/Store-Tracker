#ifndef PRODUCT_H
#define PRODUCT_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class product;
}

class product : public QDialog
{
    Q_OBJECT

public:
    explicit product(QWidget *parent = nullptr);
    ~product();

private:
    Ui::product *ui;
    QSqlDatabase conn;

};

#endif // PRODUCT_H

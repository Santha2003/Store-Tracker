#ifndef VOUCHER_UPDATE_H
#define VOUCHER_UPDATE_H

#include <QDialog>

namespace Ui {
class voucher_update;
}

class voucher_update : public QDialog
{
    Q_OBJECT

public:
    explicit voucher_update(QWidget *parent = nullptr);
    ~voucher_update();

private:
    Ui::voucher_update *ui;
};

#endif // VOUCHER_UPDATE_H

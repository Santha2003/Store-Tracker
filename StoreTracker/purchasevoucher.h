#ifndef PURCHASEVOUCHER_H
#define PURCHASEVOUCHER_H

#include <QDialog>

namespace Ui {
class purchaseVoucher;
}

class purchaseVoucher : public QDialog
{
    Q_OBJECT

public:
    explicit purchaseVoucher(QWidget *parent = nullptr);
    ~purchaseVoucher();

private:
    Ui::purchaseVoucher *ui;
};

#endif // PURCHASEVOUCHER_H

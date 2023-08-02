#include "voucher_update.h"
#include "ui_voucher_update.h"

voucher_update::voucher_update(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::voucher_update)
{
    ui->setupUi(this);
}

voucher_update::~voucher_update()
{
    delete ui;
}

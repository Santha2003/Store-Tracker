#include "purchasevoucher.h"
#include "ui_purchasevoucher.h"
#include<QDate>


purchaseVoucher::purchaseVoucher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::purchaseVoucher)
{
    ui->setupUi(this);


    QString date=QDate::currentDate().toString("dd/MM/yyyy");

    ui->date->setText(date);
    ui->voucher->setText("1");


}

purchaseVoucher::~purchaseVoucher()
{
    delete ui;
}

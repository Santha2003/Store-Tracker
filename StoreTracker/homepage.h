#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include <companydetails.h>
#include <purchase.h>
#include <product.h>
#include <companydata.h>
#include <sales.h>
#include <purchase_voucher.h>
#include <adminloginpage.h>



namespace Ui {
class homepage;
}

class homepage : public QMainWindow
{
    Q_OBJECT

public:
    explicit homepage(QWidget *parent = nullptr);
    ~homepage();
signals:
    void acessui();

public slots:
    void getuihome();
    void get();
    void nopage();


private slots:
    void on_actionuser_Management_triggered();

    void on_actioncompanydetails_triggered();

    void on_pushButton_purchase_clicked();



    void on_actionProducts_triggered();



    void on_actionCompany_triggered();



    void on_pushButton_sales_clicked();

    void on_pushButton_clicked();



    void on_pushButton_voucher_clicked();

private:
    Ui::homepage *ui;
    companydetails *company;
    companydetails *comp;

    purchase *pchase;
    product *prod;
    companydata *cmpdetails;
    sales *sal;
    Purchase_Voucher *voucher;







};

#endif // HOMEPAGE_H

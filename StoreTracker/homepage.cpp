#include "homepage.h"
#include "ui_homepage.h"
#include "adminloginpage.h"
#include "companydetails.h"
#include "purchase.h"
#include "login.h"
#include<QDate>
#include <adminpage.h>
#include <QLabel>


homepage::homepage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::homepage)
{
    ui->setupUi(this);
    this->setWindowTitle("Store");

        QStatusBar *status=new QStatusBar(this);
        setStatusBar(status);
        QString date=QDate::currentDate().toString();
        QLabel *message=new QLabel(date,this);
        message->setAlignment(Qt::AlignRight);
        status->addPermanentWidget(message);
         pchase=new purchase();
         company=new companydetails();
         comp=new companydetails();
         prod=new product();
         cmpdetails=new companydata();
         sal=new sales();
         voucher=new Purchase_Voucher();




        connect(voucher,SIGNAL(setui()),this,SLOT(getuihome()),Qt::DirectConnection);
        connect(this,SIGNAL(acessui()),comp,SLOT(uiacess()));
        connect(voucher,SIGNAL(pass()),this,SLOT(get()));
}

homepage::~homepage()
{
    delete ui;
}

void homepage::getuihome()
{

    comp->show();
    emit acessui();
}

void homepage::get()
{
    pchase->show();
}

void homepage::nopage()
{
    ui->actionuser_Management->setVisible(false);
}





void homepage::on_actionuser_Management_triggered()
{
    adminpage *log=new adminpage();
        log->show();
}


void homepage::on_actioncompanydetails_triggered()
{

    company->show();
}


void homepage::on_pushButton_purchase_clicked()
{

        pchase->show();
}


void homepage::on_actionProducts_triggered()
{
       prod->show();
}







void homepage::on_actionCompany_triggered()
{
    cmpdetails->show();
}




void homepage::on_pushButton_sales_clicked()
{
    sal->show();
}







void homepage::on_pushButton_voucher_clicked()
{
    voucher->show();
}


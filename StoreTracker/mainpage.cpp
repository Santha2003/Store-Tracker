#include "mainpage.h"
#include "ui_mainpage.h"
#include "adminloginpage.h"

mainpage::mainpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainpage)
{
    ui->setupUi(this);
}

mainpage::~mainpage()
{
    delete ui;
}

void mainpage::on_pushButton_admin_clicked()
{


}


#include "login.h"
#include "ui_login.h"
#include "adminloginpage.h"
#include "userlogin.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");
}

login::~login()
{
    delete ui;
}




void login::on_pushButton_admin_clicked()
{
    this->hide();
    adminloginpage *admin=new adminloginpage();
    admin->show();

}


void login::on_pushButton_user_clicked()
{
    this->hide();
    userlogin *user=new userlogin();
    user->show();
}


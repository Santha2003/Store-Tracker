#include "adminloginpage.h"
#include "ui_adminloginpage.h"
#include "homepage.h"
#include <QMessageBox>
#include "adminpage.h"
#include <QRegularExpression>

adminloginpage::adminloginpage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::adminloginpage)
{
    ui->setupUi(this);

    ui->lineEdit_username->setPlaceholderText("Username");
    ui->lineEdit_password->setPlaceholderText("password");


    ui->lineEdit_username->setClearButtonEnabled(true);
    ui->lineEdit_password->setClearButtonEnabled(true);
}

adminloginpage::~adminloginpage()
{
    delete ui;
}




void adminloginpage::on_pushButtonLogin_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();

//    if(username.isEmpty() && !password.isEmpty())
//    {
//        QMessageBox::information(this,"Admin_Login","Enter the username");

//    }
//    if(password.isEmpty() && !username.isEmpty())
//    {
//        QMessageBox::information(this,"Admin_login","Enter the Password");

//    }
//    if(username.isEmpty() && password.isEmpty())
//    {
//        QMessageBox::information(this,"Admin_Login","Please fill username and password");

//    }

    QRegularExpression regex("^[a-zA-Z]+$");
    bool isValid = regex.match(username).hasMatch();
    if (isValid && !username.isEmpty()) {
       qDebug()<<"hi hru";
    } else {
        QMessageBox::information(this,"Admin_Login","Enter correct Username");

    }
    if(username=="santha" && password=="santha1234")
    {

        this->hide();
        homepage *home=new homepage();
        home->show();
    }
    else
    {
        QMessageBox::warning(this,"login","Invalid Login");
    }

}




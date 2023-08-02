#include "userlogin.h"
#include "ui_userlogin.h"
#include "homepage.h"
#include "billing_form.h"
#include <QMessageBox>
#include <QSettings>
#include <QRegularExpression>

userlogin::userlogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userlogin)
{
    ui->setupUi(this);
    home=new homepage();
    connect(this,SIGNAL(page()),home,SLOT(nopage()));



}

userlogin::~userlogin()
{
    delete ui;
}

void userlogin::on_pushButton_userlogin_clicked()
{
    QSettings settings("company", "MyApplication");
    QString dbname = settings.value("dbname").toString();
      conn=QSqlDatabase::addDatabase("QSQLITE");
    conn.setDatabaseName(QString("C:/Users/prabh/Desktop/db/%1.db").arg(dbname));

    int sum = 0;

    if (conn.open()) {
        QString username = ui->lineEdit_user->text();
        QString password = ui->lineEdit_user_password->text();
        int check=0;
        if(username.isEmpty() && !password.isEmpty())
        {
            QMessageBox::information(this,"User_Login","Enter the username");
            check=1;
        }
        if(password.isEmpty() && !username.isEmpty())
        {
            QMessageBox::information(this,"User_login","Enter the Password");
            check=1;
        }
        if(username.isEmpty() && password.isEmpty())
        {
            QMessageBox::information(this,"User_Login","Please fill username and password");
            check=1;
        }

        QRegularExpression regex("^[a-zA-Z0-9_]+$");
        bool isValid = regex.match(username).hasMatch();
        if (isValid && !username.isEmpty()) {
           qDebug()<<"hi hru";
        } else {
            QMessageBox::information(this,"User_Login","Enter correct Username");
            check=1;
        }








        sum = 1;

        QSqlQuery qry;
        qry.prepare("SELECT * FROM user_login WHERE Username = :username AND Password = :password");
        qry.bindValue(":username", username);
        qry.bindValue(":password", password);

        if (qry.exec()) {
            int count=0;
            while (qry.next()) {
                count=1;

            }

            if (count==1 && sum == 1&& check==0) {
                QMessageBox::information(this, "Login", "Login successful");
                this->close();
                home->show();
                emit page();


            } else {
                QMessageBox::information(this, "Login", "Login not successful");
            }
        } else {
            QMessageBox::information(this, "Error", "Query execution failed: " + qry.lastError().text());
        }
    } else {
        QMessageBox::information(this, "Error", "Database not connected");
    }

    conn.close();
    QSqlDatabase::removeDatabase("QSQLITE");
}




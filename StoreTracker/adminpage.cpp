#include "adminpage.h"
#include "ui_adminpage.h"
#include <QSettings>
#include <QMessageBox>
#include "QSqlDatabase"
#include <QSqlQuery>
#include <QDebug>
#include <QSettings>
#include <QLabel>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlTableModel>

adminpage::adminpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminpage)
{
    ui->setupUi(this);
    this->setWindowTitle("admin");
}

adminpage::~adminpage()
{
    delete ui;
}
void adminpage::on_pushButton_saveuser_clicked()
{
    QSettings settings("company", "MyApplication");
    QString dbname = settings.value("dbname").toString();
    conn=QSqlDatabase::addDatabase("QSQLITE");
    conn.setDatabaseName(QString("C:/Users/prabh/Desktop/db/%1.db").arg(dbname));
    qDebug()<<dbname;
    if(conn.open())
    {
        QSqlQuery a;
        a.exec("create table user_login""(Id integer primary key autoincrement,""Username varchar(20),""Password varchar(30))");
        QString username=ui->lineEdit_user->text();
        QString password=ui->lineEdit_userpass->text();

        QSqlQuery qry;
        if(username!=""&& password!="")
        {
            qry.prepare("INSERT INTO user_login  (Username,Password) VALUES (:Username,:Password)");
            qry.bindValue(":Username",username);
            qry.bindValue(":Password",password);
            if (qry.exec()) {
                QMessageBox::information(this, "UserLogin", "saved!");

            }

        }
        else
        {
            QMessageBox::information(this,"UserLogin","Please fill all deatils");
        }

    }
    else
    {
        QMessageBox::information(this, "Not connected", "Database not connected");
    }
    conn.close();
    QSqlDatabase::removeDatabase("QSQLITE");
}


void adminpage::on_pushButton_view_clicked()
{
    {
        QSettings settings("company", "MyApplication");
        QString dbname = settings.value("dbname").toString();

         conn = QSqlDatabase::addDatabase("QSQLITE");
        conn.setDatabaseName(QString("C:/Users/prabh/Desktop/db/%1.db").arg(dbname));

        if (conn.open()) {
            qWarning() << "Database opened successfully";
            QSqlQueryModel * model=new QSqlQueryModel();
           QSqlQuery query("SELECT * FROM user_login", conn);
           query.exec();
           model->setQuery(query);
           ui->tableView->setModel(model);
           qDebug()<<(model->rowCount());


        }
        else {
            qWarning() << "Failed to open database";
        }
        conn.close();
        QSqlDatabase::removeDatabase("QSQLITE");
    }


}


void adminpage::on_pushButton_delete_clicked()
{
    QSettings settings("company", "MyApplication");
    QString dbname = settings.value("dbname").toString();

     conn = QSqlDatabase::addDatabase("QSQLITE");
    conn.setDatabaseName(QString("C:/Users/prabh/Desktop/db/%1.db").arg(dbname));

    if (conn.open())
    {
        QModelIndex index=ui->tableView->currentIndex();
                qDebug()<<index;
                if (!index.isValid()) {
                    // No row is selected
                    QMessageBox::information(this,"Delete","please click anyone");

                }

    QVariant id = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0));
    int rowId = id.toInt();
    qDebug()<<rowId;
    QSqlQuery query;
     query.prepare("DELETE FROM user_login WHERE Id =:rowId");
     query.bindValue(":rowId",rowId);
     query.exec();
     QSqlQueryModel *model = new QSqlQueryModel();
      query.prepare("select * from user_login");
      query.exec();
       model->setQuery(query);
      ui->tableView->setModel(model);
    }
    conn.close();
    QSqlDatabase::removeDatabase("QSQLITE");
}


#include "companydata.h"
#include "ui_companydata.h"
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


companydata::companydata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::companydata)
{
    ui->setupUi(this);
    this->setWindowTitle("company");
    QSettings settings("company", "MyApplication");
    QString dbname = settings.value("dbname").toString();

     conn = QSqlDatabase::addDatabase("QSQLITE");
    conn.setDatabaseName(QString("C:/Users/prabh/Desktop/db/%1.db").arg(dbname));

    if (conn.open()) {
        qWarning() << "Database opened successfully";
        QSqlQueryModel * model=new QSqlQueryModel();
       QSqlQuery query("SELECT * FROM Purchase_companydetails", conn);
       query.exec();
       model->setQuery(query);
       ui->tableView->setModel(model);



    }
    else {
        qWarning() << "Failed to open database";
    }
    conn.close();
    QSqlDatabase::removeDatabase("QSQLITE");
}

companydata::~companydata()
{
    delete ui;
}

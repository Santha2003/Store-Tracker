#include "product.h"
#include "ui_product.h"
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


product::product(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::product)
{
    ui->setupUi(this);
    this->setWindowTitle("Product");
    QSettings settings("company", "MyApplication");
    QString dbname = settings.value("dbname").toString();

     conn = QSqlDatabase::addDatabase("QSQLITE");
    conn.setDatabaseName(QString("C:/Users/prabh/Desktop/db/%1.db").arg(dbname));

    if (conn.open()) {
        qWarning() << "Database opened successfully";
        QSqlQueryModel * model=new QSqlQueryModel();
       QSqlQuery query("SELECT * FROM Purchase", conn);
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

product::~product()
{
    delete ui;
}

#include "purchase.h"
#include "ui_purchase.h"
#include "homepage.h"
#include "qdebug.h"
#include "companydetails.h"
#include <QMessageBox>
#include "QSqlDatabase"
#include <QSqlQuery>
#include <QDebug>
#include <QSettings>
#include <QLabel>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QRegularExpression>
#include <QSqlTableModel>

purchase::purchase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::purchase)
{
    ui->setupUi(this);

   ui->radioButton_goods->setChecked(true);
    this->setWindowTitle("Product");
    ui->comboBox_tax->addItem("5%", 5);
    ui->comboBox_tax->addItem("12%", 12);





}

purchase::~purchase()
{

    delete ui;
}


void purchase::on_comboBox_tax_currentTextChanged(const QString &arg1)
{

    float value = ui->comboBox_tax->currentData().toInt();

        value /= 2;
        qDebug() << value;


    ui->CGST->setText(QString::number(value));
    ui->SGST->setText(QString::number(value));
//    QString name = settings.value("dbname").toString();
//    qDebug() << "Name: " << name;
}







void purchase::on_pushButton_add_clicked()
{
    QSettings settings("company", "MyApplication");
    QString dbname = settings.value("dbname").toString();
      conn=QSqlDatabase::addDatabase("QSQLITE");
    conn.setDatabaseName(QString("C:/Users/prabh/Desktop/db/%1.db").arg(dbname));
    qDebug()<<dbname;
    if(conn.open())
    {

        QSqlQuery a;
        a.exec("create table Purchase""(Id integer primary key autoincrement,""Product_types varchar(20),""Product_name varchar(15),""Hsn_number integer,""Unit integer,""Tax varchar(20),""Cgst varchar(20),""Sgst varchar(20))");
        QString selectedValue;
        if (ui->radioButton_goods->isChecked()) {
            selectedValue = "goods";
        } else if (ui->radioButton_service->isChecked()) {
            selectedValue = "service";
        }



        QString Productname=ui->productname->text().toUpper();

        QString Hsn_number=ui->hsn->text();


        QString Unit=ui->unit->text();
        QString Tax=ui->comboBox_tax->currentText();
         QString Cgst=ui->CGST->text();
        QString Sgst=ui->SGST->text();





        QSqlQuery qry;
        if (selectedValue!="" && Productname!="" && Hsn_number!="" && Unit!="" && Tax!="" && Cgst!="" && Sgst!="") {
            int sum=0;
            QRegularExpression regex("^[a-zA-Z0-9_]+$");
            bool isValid = regex.match(Productname).hasMatch();
            if (isValid && !Productname.isEmpty()) {
               qDebug()<<"hi hru";
            } else {
                QMessageBox::information(this,"Product","Product Name only characters and numbers");
                sum=1;

            }
            int s=0;
            QRegularExpression hsnregex("^[0-9_]{8}$");
            bool hsnvalid = hsnregex.match(Hsn_number).hasMatch();
            if (hsnvalid && !Hsn_number.isEmpty()) {
               qDebug()<<"hi hru";
            } else {
                QMessageBox::information(this,"Product","Hsn number only allow 8 digits numbers");
                s=1;

            }

            qry.prepare("INSERT INTO Purchase  (Product_types,  Product_name,Hsn_number ,Unit , Tax, Cgst,Sgst) VALUES (:Product_types, :Product_name, :Hsn_number, :Unit, :Tax, :Cgst,:Sgst)");
             qry.bindValue(":Product_types",selectedValue );

             qry.bindValue(":Product_name",Productname);
             qry.bindValue(":Hsn_number",Hsn_number);
             qry.bindValue(":Unit",Unit);
             qry.bindValue(":Tax",Tax);
             qry.bindValue(":Cgst",Cgst);
             qry.bindValue(":Sgst",Sgst);
             if (qry.exec()&& sum==0 && s==0) {
                 QMessageBox::information(this, "purchase", "saved!");

                 ui->productname->clear();
                 ui->hsn->clear();
                 ui->comboBox_tax->clear();
                 ui->CGST->clear();
                 ui->SGST->clear();
                 ui->unit->clear();


             }

        }
        else
        {
            QMessageBox::information(this,"purchase","Please fill all deatils");
        }

    }
    else
    {
        QMessageBox::information(this, "Not connected", "Database not connected");
    }
    conn.close();
    QSqlDatabase::removeDatabase("QSQLITE");

}








void purchase::on_pushButton_alter_clicked()
{
    QSettings settings("company", "MyApplication");
    QString dbname = settings.value("dbname").toString();
      conn=QSqlDatabase::addDatabase("QSQLITE");
    conn.setDatabaseName(QString("C:/Users/prabh/Desktop/db/%1.db").arg(dbname));
    if(conn.open())
    {


        QString selectedValue;
        if (ui->radioButton_goods->isChecked()) {
            selectedValue = "goods";
        } else if (ui->radioButton_service->isChecked()) {
            selectedValue = "service";
        }

        QString Productname=ui->productname->text();
        QString Hsn_number=ui->hsn->text();
        QString Unit=ui->unit->text();
        QString Tax=ui->comboBox_tax->currentText();
         QString Cgst=ui->CGST->text();
        QString Sgst=ui->SGST->text();
        QSqlQuery qry;

        QModelIndex index=ui->tableView->currentIndex();
        qDebug()<<index;

       QVariant val=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0));
       int id=val.toInt();
       qDebug()<<val;
        if (selectedValue!="" && Productname!="" && Hsn_number!="" && Unit!="" && Tax!="" && Cgst!="" && Sgst!="") {


            qry.prepare("update Purchase set Product_types=:Product_types,  Product_name=:Product_name,Hsn_number=:Hsn_number ,Unit=:Unit , Tax=:Tax, Cgst=:Cgst,Sgst=:Sgst where Id=:id");
             qry.bindValue(":Product_types",selectedValue );

             qry.bindValue(":Product_name",Productname);
             qry.bindValue(":Hsn_number",Hsn_number);
             qry.bindValue(":Unit",Unit);
             qry.bindValue(":Tax",Tax);
             qry.bindValue(":Cgst",Cgst);
             qry.bindValue(":Sgst",Sgst);
             qry.bindValue(":id",id);
             if (qry.exec()) {
                 QSqlQuery query;
                 QMessageBox::information(this, "purchase", "Update Successfully");

                 ui->productname->clear();
                 ui->hsn->clear();
                 ui->comboBox_tax->clear();
                 ui->CGST->clear();
                 ui->unit->clear();
                 ui->SGST->clear();
                 QSqlQueryModel *model = new QSqlQueryModel();
                  query.prepare("select * from Purchase");
                  query.exec();
                   model->setQuery(query);
                  ui->tableView->setModel(model);

             }

        }
        else
        {
            QMessageBox::information(this,"purchase","Please fill all deatils");
        }

    }
    else
    {
        QMessageBox::information(this, "Not connected", "Database not connected");
    }
    conn.close();
    QSqlDatabase::removeDatabase("QSQLITE");
}


void purchase::on_pushButton_cancel_clicked()
{
    this->close();


}














void purchase::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    QSettings settings("company", "MyApplication");
    QString dbname = settings.value("dbname").toString();

     conn = QSqlDatabase::addDatabase("QSQLITE");
    conn.setDatabaseName(QString("C:/Users/prabh/Desktop/db/%1.db").arg(dbname));

    if (conn.open()) {
              QSqlQuery query;
              query.prepare("select * from Purchase where Id='"+val+"' or Product_types='"+val+"' or  Product_name='"+val+"' or Hsn_number='"+val+"' or Unit='"+val+"' or Tax='"+val+"' or Cgst='"+val+"' or Sgst='"+val+"' " );
              if(query.exec())
              {
                  while(query.next())
                  {
                      if(query.value(1)=="goods"){
                           ui->radioButton_goods->setChecked(true);
                       }
                       if(query.value(1)=="service"){
                           ui->radioButton_service->setChecked(true);
                       }

                       ui->productname->setText(query.value(2).toString());
                       ui->hsn->setText(query.value(3).toString());
                       ui->unit->setValue(query.value(4).toInt());
                       ui->comboBox_tax->setCurrentText(query.value(5).toString());
                       ui->CGST->setText(query.value(6).toString());
                       ui->SGST->setText(query.value(7).toString());
                  }
              }
    }
    conn.close();
    QSqlDatabase::removeDatabase("QSQLITE");

}


void purchase::on_pushButton_show_clicked()
{
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
       qDebug()<<(model->rowCount());


    }
    else {
        qWarning() << "Failed to open database";
    }
    conn.close();
    QSqlDatabase::removeDatabase("QSQLITE");
}




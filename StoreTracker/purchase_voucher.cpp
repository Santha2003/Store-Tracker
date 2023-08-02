#include "purchase_voucher.h"
#include "ui_purchase_voucher.h"
#include <QDate>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <purchase.h>
Purchase_Voucher::Purchase_Voucher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Purchase_Voucher)
{
    ui->setupUi(this);

    this->setWindowTitle("PurchaseVoucher");
     QString date=QDate::currentDate().toString();
     ui->date->setText(date);

QString vou=ui->voucher->text();
     QSettings settings("MyCompany", "MyApp");


     int currentValue = settings.value("id1", 1).toInt();

          ui->voucher->setText(QString::number(currentValue));
          qDebug()<<currentValue;

















}

Purchase_Voucher::~Purchase_Voucher()
{
    delete ui;
}

void Purchase_Voucher::on_tableWidget_cellChanged(int row, int column)
{
    if(column==0){
        QString product=ui->tableWidget->item(row,column)->text().toUpper();
        qDebug()<<product;
        QSettings settings("company", "MyApplication");
        QString dbname = settings.value("dbname").toString();
        conn = QSqlDatabase::addDatabase("QSQLITE");
        conn.setDatabaseName(QString("C:/Users/prabh/Desktop/db/%1.db").arg(dbname));
        if(conn.open())
        {
            QSqlQuery qry;
            qry.prepare("SELECT Product_name FROM Purchase WHERE Product_name = :Product_name");
                    qry.bindValue(":Product_name",product);
            if(qry.exec() && qry.next())
            {
                QSqlQuery qry1;
                qry1.prepare("SELECT Hsn_number, Cgst, Sgst FROM Purchase WHERE Product_name = :Product_name");
                qry1.bindValue(":Product_name", product);
                qry1.exec();
                if (qry1.next()) {
                    QTableWidgetItem *item1 = new QTableWidgetItem(qry1.value(0).toString());
                    ui->tableWidget->setItem(row, 1, item1);
                    QTableWidgetItem *item2=new QTableWidgetItem(qry1.value(1).toString());
                            ui->tableWidget->setItem(row,4,item2);
                    QTableWidgetItem *item3= new QTableWidgetItem(qry1.value(2).toString());
                    ui->tableWidget->setItem(row,6,item3);

                } else {
                    qDebug() << "Query failed or no results";
                }


            }
            else
            {

                emit pass();
            }

        }
    }
        if(column==3){
            float cgst=ui->tableWidget->item(row,4)->text().toFloat();
            qDebug()<<cgst;
            int quantity=ui->tableWidget->item(row,2)->text().toInt();
            qDebug()<<quantity;
            int price=ui->tableWidget->item(row,3)->text().toInt();
            qDebug()<<price;
            double sum=0.0;
            double total=0.0;
            total=quantity*price;
            sum=(cgst/100)*(total);
            qDebug()<<sum;
            QTableWidgetItem *item4=new QTableWidgetItem(QString::number(sum));
            ui->tableWidget->setItem(row,5,item4);
            QTableWidgetItem *item5=new QTableWidgetItem(QString::number(sum));
            ui->tableWidget->setItem(row,7,item5);
            double totalvalue=(quantity*price)+(sum+sum);
            QTableWidgetItem *item6=new QTableWidgetItem(QString::number(totalvalue));
                    ui->tableWidget->setItem(row,8,item6);
                    grand_Total+=totalvalue;
                    ui->total->setText(QString::number(grand_Total));

        }
//        int quantity=ui->tableWidget->item(row,2)->text().toInt();
//        int price=ui->tableWidget->item(row,3)->text().toInt();
//        int taxrate=ui->tableWidget->item(row,5)->text().toInt();
//        double totalvalue=(quantity*price)+(taxrate+taxrate);
//        QTableWidgetItem *item6=new QTableWidgetItem(QString::number(totalvalue));
//                ui->tableWidget->setItem(row,8,item6);



                if (column == ui->tableWidget->columnCount() - 1) { // Check if last column
                    int newRow = ui->tableWidget->rowCount();
                    ui->tableWidget->insertRow(newRow);
                }

}


void Purchase_Voucher::on_lineEdit_company_editingFinished()
{
    QSettings settings("company", "MyApplication");
    QString dbname = settings.value("dbname").toString();
    conn = QSqlDatabase::addDatabase("QSQLITE");
    conn.setDatabaseName(QString("C:/Users/prabh/Desktop/db/%1.db").arg(dbname));

    if(conn.open()){
         QString value = ui->lineEdit_company->text();

         QSqlQuery qry;
    qry.prepare("SELECT Name FROM Purchase_companydetails WHERE Name = :Name");
    qry.bindValue(":Name", value);

        if (qry.exec() && qry.next()) {
            qDebug() << "Name exists";
           }
         else {

            emit setui();
        }
    }
    else
    {
        QMessageBox::information(this, "Company", " Database Not Connection");
    }


    conn.close();
    QSqlDatabase::removeDatabase("QSQLITE");
}




void Purchase_Voucher::on_pushButton_save_voucher_clicked()
{
    int rows=ui->tableWidget->rowCount();



    QSettings settings("company", "MyApplication");
    QString dbname = settings.value("dbname").toString();
    conn = QSqlDatabase::addDatabase("QSQLITE");
    conn.setDatabaseName(QString("C:/Users/prabh/Desktop/db/%1.db").arg(dbname));
    if(conn.open())
    {
        QSqlQuery b;
        b.exec("create table Purchase_Voucher""(Id integer primary key autoincrement,""Voucher_no varchar(20),""Date DATE,""Company_Name varchar(40),""Product_Name varchar(20),""Hsn_Number integer,""Quantity integer,""Price integer,""CGST integer,""CRate integer,""SGST integer,""SRate integer,""Total varchar(100))");
        for(int row=0;row<rows-1;row++)
        {
            qDebug()<<"HI";

                QString companyname=ui->lineEdit_company->text();
                if(companyname.isEmpty()){
                    QMessageBox::information(this,"Purchase_VOucher","Fill companyname");
                }
                QString date=ui->date->text();
                QString voucherno=ui->voucher->text();
                QString pname = ui->tableWidget->item(row,0)->text().toUpper();
                QString hsnnumber = ui->tableWidget->item(row,1)->text();
                QString quanty = ui->tableWidget->item(row,2)->text();
                QString qprice = ui->tableWidget->item(row,3)->text();
                QString cgst = ui->tableWidget->item(row,4)->text();
                QString rate = ui->tableWidget->item(row,5)->text();
                QString sgst = ui->tableWidget->item(row,6)->text();
                QString rate1 = ui->tableWidget->item(row,7)->text();
                QString ptotal = ui->tableWidget->item(row,8)->text();
                QSqlQuery a;
                a.prepare("INSERT INTO Purchase_Voucher (Voucher_no,Date,Company_Name,Product_Name,Hsn_Number,Quantity,Price,CGST,CRate,SGST,SRate,Total) VALUES (:Voucher_no,:Date,:Company_Name,:Product_Name,:Hsn_Number,:Quantity,:Price,:CGST,:CRate,:SGST,:SRate,:Total )");
                a.bindValue(":Voucher_no",voucherno);
                a.bindValue(":Date",date);
                a.bindValue(":Company_Name",companyname);
                a.bindValue(":Product_Name",pname);
                a.bindValue(":Hsn_Number",hsnnumber);
                a.bindValue(":Quantity",quanty);
                a.bindValue(":Price",qprice);
                a.bindValue(":CGST",cgst);
                a.bindValue(":CRate",rate);
                a.bindValue(":SGST",sgst);
                a.bindValue(":SRate",rate1);
                a.bindValue(":Total",ptotal);

                if (a.exec()) {
                    QMessageBox::information(this, "purchase_voucher", "saved!");
                    QSettings settings("MyCompany", "MyApp");
                    int currentValue = settings.value("id1", 1).toInt();
                    int newvalue=currentValue+1;
                    settings.setValue("id1",newvalue);
                    QSqlQuery c;
                    c.prepare("select Unit FROM Purchase WHERE Product_name = :Product_name");
                    c.bindValue(":Product_name",pname);
                     if (c.exec() && c.next()) {
                         int unitValue = c.value(0).toInt();
                         int total=quanty.toInt();
                         int sum=unitValue+total;
//                         qDebug()<<unitValue;
//                         qDebug()<<total;
//                         qDebug()<<sum;
                         c.prepare("update Purchase set Unit = :Unit WHERE Product_name = :Product_name");
                         c.bindValue(":Unit", sum);
                         c.bindValue(":Product_name", pname);
                         c.exec();
                        ui->tableWidget->clearContents();
                        ui->tableWidget->setRowCount(1);
                        ui->voucher->clear();
                        ui->lineEdit_company->clear();
                        ui->voucher->setText(QString::number(newvalue));

                     }

                }
                else
                {
                    QMessageBox::information(this,"Purchase_voucher","Not saved");
                }




        }
    }
    else
    {
        QMessageBox::information(this,"Purchase_Voucher","Database not Connected");
    }
    conn.close();
    QSqlDatabase::removeDatabase("QSQLITE");
}

void Purchase_Voucher::on_pushButton_alter_clicked()
{

}


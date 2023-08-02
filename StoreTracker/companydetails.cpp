#include "companydetails.h"
#include "ui_companydetails.h"
#include "homepage.h"
#include "purchase.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QRegularExpression>
#include <QObject>
#include <QSettings>

companydetails::companydetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::companydetails)
{
    ui->setupUi(this);
    this->setWindowTitle("Store  Company Details");
    ui->comboBox_startdate->addItem("2023");
          ui->comboBox_startdate->addItem("2024");
          ui->comboBox_startdate->addItem("2025");
          ui->comboBox_state->addItem("Andhra Pradesh");
                 ui->comboBox_state->addItem("Arunachal Pradesh");
                 ui->comboBox_state->addItem("Assam");
                 ui->comboBox_state->addItem("Bihar");
                 ui->comboBox_state->addItem("Chhattisgarh");
                 ui->comboBox_state->addItem("Goa");
                 ui->comboBox_state->addItem("Gujarat");
                 ui->comboBox_state->addItem("Haryana");
                 ui->comboBox_state->addItem("Himachal Pradesh");
                 ui->comboBox_state->addItem("Jharkhand");
                 ui->comboBox_state->addItem("Karnataka");
                 ui->comboBox_state->addItem("Kerala");
                 ui->comboBox_state->addItem("Madhya Pradesh");
                 ui->comboBox_state->addItem("Maharashtra");
                 ui->comboBox_state->addItem("Manipur");
                 ui->comboBox_state->addItem("Meghalaya");
                 ui->comboBox_state->addItem("Mizoram");
                 ui->comboBox_state->addItem("Nagaland");
                 ui->comboBox_state->addItem("Odisha");
                 ui->comboBox_state->addItem("Punjab");
                 ui->comboBox_state->addItem("Rajasthan");
                 ui->comboBox_state->addItem("Sikkim");
                 ui->comboBox_state->addItem("Tamil Nadu");
                 ui->comboBox_state->addItem("Telangana");
                 ui->comboBox_state->addItem("Tripura");
                 ui->comboBox_state->addItem("Uttarakhand");
                 ui->comboBox_state->addItem("Uttar Pradesh");
                 ui->comboBox_state->addItem("West Bengal");


}

companydetails::~companydetails()
{
    delete ui;
}

void companydetails::uiacess()
{
      ui->label_7->setVisible(false);
      ui->label_8->setVisible(false);
      ui->comboBox_startdate->setVisible(false);
      ui->label_9->setVisible(false);
      ui->comboBox_Enddate->setVisible(false);
      ui->label_10->setVisible(false);
}











void companydetails::on_pushButton_clicked()
{

    if(ui->comboBox_startdate->isVisible()==1){
    name = ui->name->text();
    qDebug()<<name;

    QSettings settings("company", "MyApplication");
    settings.setValue("dbname", name);

            QSqlDatabase  conn=QSqlDatabase::addDatabase("QSQLITE");
            conn.setDatabaseName(QString("C:/Users/prabh/Desktop/db/%1.db").arg(name));
          if(conn.open()){
              QSqlQuery a;
              a.exec("create table companydetails""(Id integer primary key autoincrement,""Name varchar(20),""Address varchar(30),""State varchar(15),""Pincode integer(6),""Gst_info varchar(15),""Financial_year_start varchar(20),""Financial_year_end varchar(20))");
              QString name = ui->name->text();
              QString address = ui->address->text();
              QString state=ui->comboBox_state->currentText();
              QString pincode=ui->pincode->text();
    //          QRegularExpression regex("\\d{6}");
    //          QRegularExpressionMatch match = regex.match(pincode);
    //          if (match.hasMatch()) {
    //                //qDebug()<<"matched";
    //          } else {
    //              QMessageBox::information(this,"pincode","Please fill correct pincode");
    //          }


              QString gst=ui->gst->text();

    //          QRegularExpression reg("\\d{8}");
    //          QRegularExpressionMatch gstMatch = reg.match(gst);
    //          if (gstMatch.hasMatch()) {
    //              //qDebug() << "matched";
    //          } else {
    //              QMessageBox::information(this, "GST", "Please fill correct GST number");
    //          }


              QString startdate=ui->comboBox_startdate->currentText();
              QString enddate=ui->comboBox_Enddate->currentText();


              QSqlQuery qry;
              if(name!="" && address!="" && state!=""&& pincode!=""&& gst!=""&&startdate!=""&&enddate!=""){
              qry.prepare("INSERT INTO companydetails (Name, Address, State, Pincode, Gst_info, Financial_year_start, Financial_year_end) VALUES (:Name, :Address, :State, :Pincode, :Gst_info, :Financial_year_start, :Financial_year_end)");

              qry.bindValue(":Name", name);
              qry.bindValue(":Address", address);
              qry.bindValue(":State", state);
              qry.bindValue(":Pincode", pincode);
              qry.bindValue(":Gst_info", gst);
              qry.bindValue(":Financial_year_start", QString("%1-04-01").arg(startdate));
              qry.bindValue(":Financial_year_end", QString("%1-03-31").arg(enddate));
              if (qry.exec()) {
                  QMessageBox::information(this, "companyDetails", "Datails saved!");
              }

            }
              else
              {
                  QMessageBox::information(this,"companyDetails","Please fill all deatils");
              }


            }
          else
          {
              QMessageBox::information(this, "Not connected", "Database not connected");
          }
          conn.close();
          QSqlDatabase::removeDatabase("QSQLITE");
    }

    if(ui->comboBox_startdate->isVisible()==0){


     //emit setDataSig(name);

        QSettings settings("company", "MyApplication");
        QString dbname = settings.value("dbname").toString();
            QSqlDatabase  conn=QSqlDatabase::addDatabase("QSQLITE");
            conn.setDatabaseName(QString("C:/Users/prabh/Desktop/db/%1.db").arg(dbname));

          if(conn.open()){
              QSqlQuery b;
              b.exec("create table Purchase_companydetails""(Id integer primary key autoincrement,""Name varchar(20),""Address varchar(30),""State varchar(15),""Pincode integer(6),""Gst_info varchar(15))");

              QString name = ui->name->text();
              QString address = ui->address->text();
              QString state=ui->comboBox_state->currentText();
              QString pincode=ui->pincode->text();
    //          QRegularExpression regex("\\d{6}");
    //          QRegularExpressionMatch match = regex.match(pincode);
    //          if (match.hasMatch()) {
    //                //qDebug()<<"matched";
    //          } else {
    //              QMessageBox::information(this,"pincode","Please fill correct pincode");
    //          }


              QString gst=ui->gst->text();

    //          QRegularExpression reg("\\d{8}");
    //          QRegularExpressionMatch gstMatch = reg.match(gst);
    //          if (gstMatch.hasMatch()) {
    //              //qDebug() << "matched";
    //          } else {
    //              QMessageBox::information(this, "GST", "Please fill correct GST number");
    //          }





              QSqlQuery qry1;
              if(name!="" && address!="" && state!=""&& pincode!=""&& gst!=""){
              qry1.prepare("INSERT INTO Purchase_companydetails (Name, Address, State, Pincode, Gst_info) VALUES (:Name, :Address, :State, :Pincode, :Gst_info)");

              qry1.bindValue(":Name", name);
              qry1.bindValue(":Address", address);
              qry1.bindValue(":State", state);
              qry1.bindValue(":Pincode", pincode);
              qry1.bindValue(":Gst_info", gst);

              if (qry1.exec()) {
                  QMessageBox::information(this, "Purchase_companyDetails", "Datails saved!");
              }

              }
              else
              {
                  QMessageBox::information(this,"Purchase_companyDetails","Please fill all deatils");
              }


        }
        else
        {
              QMessageBox::information(this, "Not connected", "Database not connected");
        }
          conn.close();
          QSqlDatabase::removeDatabase("QSQLITE");
    }

}











void companydetails::on_comboBox_startdate_currentTextChanged(const QString &arg1)
{
    ui->comboBox_Enddate->clear();
        QString year=QString::number(ui->comboBox_startdate->currentText().toInt()+1);
        ui->comboBox_Enddate->addItem(year);
}


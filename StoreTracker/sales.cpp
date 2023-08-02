#include "sales.h"
#include "ui_sales.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSettings>
#include <QSqlQuery>
#include <QDebug>
sales::sales(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sales)
{
    ui->setupUi(this);
    this->setWindowTitle("sales");
    ui->comboBox_gst->addItem("5%", 5);
    ui->comboBox_gst->addItem("12%", 12);

     ui->radioButton_regular->setChecked(true);
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

sales::~sales()
{
    delete ui;
}



void sales::on_pushButton_save_clicked()
{
    QSettings settings("company", "MyApplication");
    QString dbname = settings.value("dbname").toString();
      conn=QSqlDatabase::addDatabase("QSQLITE");
    conn.setDatabaseName(QString("C:/Users/prabh/Desktop/db/%1.db").arg(dbname));
    if(conn.open())
    {
        QSqlQuery query;
        query.exec("create table sales""(Id integer primary key autoincrement,""Types varchar(20),""Company_Name varchar(30),""Address varchar(100),""State varchar(15),""Pincode integer,""Gst_info varchar(25),""Hsn integer,""Product_name varchar(50),""Units integer,""Gst varchar(10),""Cgst varchar(10),""Sgst varchar(10))");
        QString selectedValue;
        if (ui->radioButton_customer->isChecked()) {
            selectedValue = "Customer";
        } else if (ui->radioButton_regular->isChecked()) {
            selectedValue = "Regular";
        }

        QString Companyname=ui->lineEdit_name->text();


        QString Address=ui->lineEdit_address->text();
        QString State=ui->comboBox_state->currentText();
        QString Pincode=ui->lineEdit_Pincode->text();

        QString Gst_info=ui->gstinfo->text();

        QString Hsn=ui->lineEdit_hsn->text();

        QString Product_name=ui->lineEdit_product->text().toUpper();
        QString Units=ui->spinBox_units->text();
        QString Gst=ui->comboBox_gst->currentText();
        QString Cgst=ui->cgst->text();
        QString Sgst=ui->sgst->text();





        if (!Product_name.isEmpty()) {
            QSqlQuery qry;
            qry.prepare("SELECT Product_name,Hsn_number FROM Purchase WHERE Product_name = :Product_name AND Hsn_number =:Hsn_number");
            qry.bindValue(":Product_name", Product_name);
            qry.bindValue(":Hsn_number",Hsn);
            if (qry.exec() && qry.next()) {



                if(Companyname!=""&& Address!=""&& State!=""&& Pincode!=""&& Gst_info!=""&& Hsn!=""&& Units!=""&&Gst!=""&& Cgst!=""&& Sgst!=""){
                                QSqlQuery qry1;
                                int sum=0,s=0,k=0,h=0;
                                QRegularExpression regex("^[a-zA-Z0-9_]+$");
                                bool isValid = regex.match(Companyname).hasMatch();
                                if (isValid && !Companyname.isEmpty()) {
                                   qDebug()<<"hi hru";
                                } else {
                                    QMessageBox::information(this,"Sales","company Name only allow characters and numbers");
                                    sum=1;

                                }
                                QRegularExpression pinregex("^[0-9_]{6}$");
                                bool pinvalid = pinregex.match(Pincode).hasMatch();
                                if (pinvalid && !Pincode.isEmpty()) {
                                   qDebug()<<"hi hru";
                                } else {
                                    QMessageBox::information(this,"Sales","Pincode only allow 6 digits numbers");
                                    s=1;

                                }
                                QRegularExpression hsnregex("^[0-9_]{8}$");
                                bool hsnvalid = hsnregex.match(Hsn).hasMatch();
                                if (hsnvalid && !Hsn.isEmpty()) {
                                   qDebug()<<"hi hru";
                                } else {
                                    QMessageBox::information(this,"Sales","Hsn number only allow 8 digits numbers");
                                    k=1;

                                }
                                QRegularExpression gstregex("^[A-Z0-9_]{15}$");
                                bool gstvalid = gstregex.match(Gst_info).hasMatch();
                                if (gstvalid && !Gst_info.isEmpty()) {
                                   qDebug()<<"hi hru";
                                } else {
                                    QMessageBox::information(this,"Sales","Gst_info only allow characters and numbers");
                                     h=1;
                                }

                                qry1.prepare("INSERT INTO sales (Types,Company_Name,Address,State,Pincode ,Gst_info,Hsn,Product_name,Units,Gst,Cgst,Sgst) VALUES (:Types,:Company_Name,:Address,:State,:Pincode ,:Gst_info,:Hsn,:Product_name,:Units,:Gst,:Cgst,:Sgst) ");
                                qry1.bindValue(":Types",selectedValue);
                                qry1.bindValue(":Company",Companyname);
                                qry1.bindValue(":Address",Address);
                                qry1.bindValue(":State",State);
                                qry1.bindValue(":Pincode",Pincode);
                                qry1.bindValue(":Gst_info",Gst_info);
                                qry1.bindValue(":Product_name",Product_name);
                                qry1.bindValue(":Units",Units);
                                qry1.bindValue(":Gst",Gst);
                                qry1.bindValue(":Cgst",Cgst);
                                qry1.bindValue(":Sgst",Sgst);
                                if (qry1.exec()&& sum==0 && s==0 && k==0 && h==0) {
                                    QMessageBox::information(this, "Sales", "Successfully Saved!");
                                    QSqlQuery a;
                                    a.prepare("select Unit FROM Purchase WHERE Product_name = :Product_name AND Hsn_number =:Hsn_number ");
                                    a.bindValue(":Product_name", Product_name);
                                    a.bindValue(":Hsn_number",Hsn);

                                    if (a.exec() && a.next()) {
                                        int unitValue = a.value(0).toInt();
                                        int total=Units.toInt();
                                        if (total < unitValue) {
                                            int sum=unitValue - total;
                                            qDebug()<<sum;
                                            a.prepare("update Purchase set Unit = :Unit WHERE Product_name = :Product_name AND Hsn_number =:Hsn_number ");
                                            a.bindValue(":Unit", sum);
                                            a.bindValue(":Product_name", Product_name);
                                            a.bindValue(":Hsn_number",Hsn);
                                            a.exec();
                                        }
                                        else
                                        {
                                            QMessageBox::information(this,"sales","Count Greater than Stock Count");
                                        }
                                    }
                                    else
                                    {
                                        QMessageBox::information(this,"sales","Error");
                                    }
                                    ui->lineEdit_name->clear();
                                    ui->lineEdit_address->clear();
                                    ui->comboBox_state->clear();
                                    ui->lineEdit_product->clear();
                                    ui->gstinfo->clear();
                                    ui->lineEdit_hsn->clear();
                                    ui->lineEdit_product->clear();
                                    ui->spinBox_units->clear();
                                    ui->comboBox_gst->clear();
                                    ui->lineEdit_Pincode->clear();
                                    ui->cgst->clear();
                                    ui->sgst->clear();








                                }
                        }
                        else
                        {
                               QMessageBox::information(this,"Sales","Please Fill All Details");
                        }

                        }
                        else {
                                QMessageBox::information(this, "Error", "Product does not exist in Purchase table");
                         }



            }
        else {
           QMessageBox::information(this, "Error", "Please enter a product name");
       }


    }
    else
    {
        QMessageBox::information(this,"Sales","Database Connection Failed");
    }
    conn.close();
    QSqlDatabase::removeDatabase("QSQLITE");
}




void sales::on_comboBox_gst_currentTextChanged(const QString &arg1)
{
    float value = ui->comboBox_gst->currentData().toInt();

        value /= 2;



    ui->cgst->setText(QString::number(value));
    ui->sgst->setText(QString::number(value));
}


void sales::on_pushButton_cancel_clicked()
{
    this->close();
}
void sales::on_radioButton_customer_clicked()
{
    ui->gstinfo->setText("000000000000000");
    ui->gstinfo->setEnabled(false);
    ui->comboBox_gst->addItem("0");


    ui->cgst->setText("0");
    ui->sgst->setText("0");
    ui->cgst->setEnabled(false);
    ui->sgst->setEnabled(false);


}


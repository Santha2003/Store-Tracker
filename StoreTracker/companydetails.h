#ifndef COMPANYDETAILS_H
#define COMPANYDETAILS_H
#include "qsqldatabase.h"
#include <QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>
#include<QFileInfo>
#include <QObject>
#include<companydetails.h>
#include <QDialog>

namespace Ui {
class companydetails;
}

class companydetails : public QDialog
{
    Q_OBJECT

public:
    explicit companydetails(QWidget *parent = nullptr);
    ~companydetails();
    Ui::companydetails* getUi() const { return ui; }



public slots:
    void uiacess();

private slots:
    void on_pushButton_clicked();


    void on_comboBox_Enddate_currentTextChanged(const QString &arg1);

    void on_commandLinkButton_clicked();

    void on_comboBox_startdate_currentTextChanged(const QString &arg1);

private:
      Ui::companydetails *ui;
      friend class purchase;

    QString name;
    QSettings settings;


};

#endif // COMPANYDETAILS_H

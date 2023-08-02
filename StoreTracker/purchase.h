#ifndef PURCHASE_H
#define PURCHASE_H

#include <QDialog>
#include <companydetails.h>
#include<QSqlDatabase>
#include<QMessageBox>
#include <qsqldatabase.h>
#include <QSettings>
#include <QSqlQueryModel>
#include <QTableView>


namespace Ui {
class purchase;
}

class purchase : public QDialog
{
    Q_OBJECT

public:
    explicit purchase(QWidget *parent = nullptr);
    ~purchase();



private slots:
    void on_comboBox_tax_currentTextChanged(const QString &arg1);
    void on_pushButton_add_clicked();

    void on_pushButton_cancel_clicked();

    void on_comboBox_alter_currentTextChanged(const QString &arg1);

    void on_pushButton_alter_clicked();

    void on_pushButton_create_clicked();

    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_show_clicked();

    void on_radioButton_service_clicked();

private:
    Ui::purchase *ui;
    QString dbname;
    QSettings settings;
    QSqlDatabase conn;
    QString COMPANY_NAME;



};

#endif // PURCHASE_H

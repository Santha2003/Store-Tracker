#ifndef PURCHASE_VOUCHER_H
#define PURCHASE_VOUCHER_H

#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSettings>
#include <QSqlDatabase>
#include <purchase.h>

namespace Ui {
class Purchase_Voucher;
}

class Purchase_Voucher : public QDialog
{
    Q_OBJECT

public:
    explicit Purchase_Voucher(QWidget *parent = nullptr);
    ~Purchase_Voucher();

signals:
   void setui();
   void pass();

private slots:
    void on_tableWidget_cellChanged(int row, int column);













    void on_lineEdit_company_editingFinished();

    void on_pushButton_save_voucher_clicked();

    void on_pushButton_clicked();

    void on_pushButton_alter_clicked();

private:
    Ui::Purchase_Voucher *ui;
    QTableWidget *tablewidget;
    QSettings Settings;
    QSqlDatabase conn;
    double grand_Total=0.0;


};

#endif // PURCHASE_VOUCHER_H

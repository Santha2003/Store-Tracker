#ifndef SALES_H
#define SALES_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSettings>

namespace Ui {
class sales;
}

class sales : public QDialog
{
    Q_OBJECT

public:
    explicit sales(QWidget *parent = nullptr);
    ~sales();


private slots:


    void on_pushButton_save_clicked();

    void on_comboBox_gst_currentTextChanged(const QString &arg1);

    void on_pushButton_cancel_clicked();

    void on_radioButton_customer_clicked();

private:
    Ui::sales *ui;
    QString selectedValue;
    QSqlDatabase conn;
    QSettings settings;
};

#endif // SALES_H

#ifndef COMPANYDATA_H
#define COMPANYDATA_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class companydata;
}

class companydata : public QDialog
{
    Q_OBJECT

public:
    explicit companydata(QWidget *parent = nullptr);
    ~companydata();

private:
    Ui::companydata *ui;
    QSqlDatabase conn;
};

#endif // COMPANYDATA_H

#ifndef COMPANY_H
#define COMPANY_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class company;
}

class company : public QDialog
{
    Q_OBJECT

public:
    explicit company(QWidget *parent = nullptr);
    ~company();

private:
    Ui::company *ui;
    QSqlDatabase conn;
};

#endif // COMPANY_H

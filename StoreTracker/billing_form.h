#ifndef BILLING_FORM_H
#define BILLING_FORM_H

#include <QMainWindow>

namespace Ui {
class Billing_form;
}

class Billing_form : public QMainWindow
{
    Q_OBJECT

public:
    explicit Billing_form(QWidget *parent = nullptr);
    ~Billing_form();

private:
    Ui::Billing_form *ui;
};

#endif // BILLING_FORM_H

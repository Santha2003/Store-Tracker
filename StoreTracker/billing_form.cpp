#include "billing_form.h"
#include "ui_billing_form.h"

Billing_form::Billing_form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Billing_form)
{
    ui->setupUi(this);

}

Billing_form::~Billing_form()
{
    delete ui;

}

#include "mianpage.h"
#include "ui_mianpage.h"
#include "adminloginpage.h"


mianpage::mianpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mianpage)
{
    ui->setupUi(this);
}

mianpage::~mianpage()
{
    delete ui;
}

void mianpage::on_pushButton_admin_clicked()
{
    adminpage page;
    page.setModal(true);
    page.exec();
}


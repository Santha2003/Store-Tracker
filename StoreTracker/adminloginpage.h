#ifndef ADMINLOGINPAGE_H
#define ADMINLOGINPAGE_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class adminloginpage; }
QT_END_NAMESPACE

class adminloginpage : public QMainWindow
{
    Q_OBJECT

public:
    adminloginpage(QWidget *parent = nullptr);
    ~adminloginpage();

private slots:


    void on_pushButtonLogin_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::adminloginpage *ui;
};
#endif // ADMINLOGINPAGE_H

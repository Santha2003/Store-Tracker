#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_admin_clicked();

    void on_pushButton_user_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H

#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QWidget>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include<QFileInfo>
#include<homepage.h>

namespace Ui {
class userlogin;
}

class userlogin : public QWidget
{
    Q_OBJECT

public:
    explicit userlogin(QWidget *parent = nullptr);
    ~userlogin();
signals:
    void page();

private slots:
    void on_pushButton_userlogin_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::userlogin *ui;
    QSqlDatabase conn;
    QSettings settings;
    homepage *home;
};

#endif // USERLOGIN_H

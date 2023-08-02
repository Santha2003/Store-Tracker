#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>
#include <QSettings>
#include <QSqlDatabase>

namespace Ui {
class adminpage;
}

class adminpage : public QDialog
{
    Q_OBJECT

public:
    explicit adminpage(QWidget *parent = nullptr);
    ~adminpage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_saveuser_clicked();

    void on_pushButton_view_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::adminpage *ui;
    QSettings settings;
    QSqlDatabase conn;
};

#endif // ADMINPAGE_H

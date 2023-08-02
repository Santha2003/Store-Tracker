#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QDialog>

namespace Ui {
class mainpage;
}

class mainpage : public QDialog
{
    Q_OBJECT

public:
    explicit mainpage(QWidget *parent = nullptr);
    ~mainpage();

private slots:
    void on_pushButton_admin_clicked();

private:
    Ui::mainpage *ui;
};

#endif // MAINPAGE_H

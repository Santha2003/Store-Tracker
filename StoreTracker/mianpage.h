#ifndef MIANPAGE_H
#define MIANPAGE_H

#include <QDialog>

namespace Ui {
class mianpage;
}

class mianpage : public QDialog
{
    Q_OBJECT

public:
    explicit mianpage(QWidget *parent = nullptr);
    ~mianpage();

private slots:
    void on_pushButton_admin_clicked();

private:
    Ui::mianpage *ui;
};

#endif // MIANPAGE_H

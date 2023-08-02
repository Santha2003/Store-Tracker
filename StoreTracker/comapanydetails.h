#ifndef COMAPANYDETAILS_H
#define COMAPANYDETAILS_H

#include <QDialog>

namespace Ui {
class comapanydetails;
}

class comapanydetails : public QDialog
{
    Q_OBJECT

public:
    explicit comapanydetails(QWidget *parent = nullptr);
    ~comapanydetails();

private:
    Ui::comapanydetails *ui;
};

#endif // COMAPANYDETAILS_H

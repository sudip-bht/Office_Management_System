#ifndef FORGETPASSWORD_H
#define FORGETPASSWORD_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class ForgetPassword;
}

class ForgetPassword : public QDialog
{
    Q_OBJECT

public:
    explicit ForgetPassword(QWidget *parent = nullptr);
    ~ForgetPassword();

private slots:


    void on_pushButton_check_clicked();

private:
    Ui::ForgetPassword *ui;
    Connection db;
};

#endif // FORGETPASSWORD_H

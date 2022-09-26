#ifndef CLIENTLOGINDIALOG_H
#define CLIENTLOGINDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include "clientsignupdialog.h"
#include "QMainWindow"
#include "ui_mainwindow.h"
#include "clientpaneldialog.h"
#include "connection.h"
#include "forgetpassword.h"


namespace Ui {
class ClientloginDialog;
}

class ClientloginDialog : public QDialog
{
    Q_OBJECT
public:


public:
    explicit ClientloginDialog(QWidget *parent = nullptr);
    ~ClientloginDialog();

private slots:
    void on_pushButton_signup_clicked();



    void on_pushButton_Home_clicked();

    void on_pushButton_forgot_password_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::ClientloginDialog *ui;
    ClientsignupDialog *login_ui;
    ClientpanelDialog *clientpanal_ui;
    QMainWindow *MainWindow();
    Connection db;
    ForgetPassword *forget_password_ui;
};

#endif // CLIENTLOGINDIALOG_H

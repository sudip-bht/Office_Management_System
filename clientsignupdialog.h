#ifndef CLIENTSIGNUPDIALOG_H
#define CLIENTSIGNUPDIALOG_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class ClientsignupDialog;
}

class ClientsignupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientsignupDialog(QWidget *parent = nullptr);
    ~ClientsignupDialog();

private slots:
    void on_pushButton_Home_clicked();



    void on_pushButton_signup_clicked();

private:
    Ui::ClientsignupDialog *ui;
    Connection db;
};

#endif // CLIENTSIGNUPDIALOG_H

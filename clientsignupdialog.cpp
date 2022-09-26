#include "clientsignupdialog.h"
#include "ui_clientsignupdialog.h"
#include "clientlogindialog.h"
#include <QMessageBox>
ClientsignupDialog::ClientsignupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientsignupDialog)
{
    this->setWindowTitle("Client Signup");
    ui->setupUi(this);
    ui->lineEdit_Client_Name->setPlaceholderText("Enter Your Name");
    ui->lineEdit_Email->setPlaceholderText("Enter Your Email");
    ui->lineEdit_Phone->setPlaceholderText("Enter Your Contact No");
    ui->lineEdit_Username->setPlaceholderText("Enter Your Username");
    ui->lineEdit_Password->setPlaceholderText("Enter Your Password");
    ui->lineEdit_Confirm_Password->setPlaceholderText("Re-enter Your Password");
}
ClientsignupDialog::~ClientsignupDialog()
{
    delete ui;
}

void ClientsignupDialog::on_pushButton_Home_clicked()
{
    this->hide();
    parent();
}


void ClientsignupDialog::on_pushButton_signup_clicked()
{
    QString Client_name,Client_email,Client_contactno,Client_username,Client_password,Client_confirmpassword;
    Client_name=ui->lineEdit_Client_Name->text();
    Client_email=ui->lineEdit_Email->text();      //gets detail of the client while signup
    Client_password=ui->lineEdit_Password->text();
    Client_confirmpassword=ui->lineEdit_Confirm_Password->text();
    Client_contactno=ui->lineEdit_Phone->text();
    Client_username=ui->lineEdit_Username->text();

    if(db.clientdbopen())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO clientdetails ( clientId, clientName, clientEmail, clientPhone)"
                      "VALUES ( :clientId, :clientName, :clientEmail, :clientPhone)");
        query.bindValue(":clientName",Client_name);
        query.bindValue(":clientEmail",Client_email);
        query.bindValue(":clientPhone",Client_contactno);

        query.exec();
        db.dbclose();
    }
    else
    {
        qDebug()<<" cannot connect to mysql error";
        return ;
    }
        db.clientdbopen();
        if(db.clientdbopen())
        {
        QSqlQuery run;
        run.prepare("INSERT INTO clientlogin(clientID, clientUsername, clientPassword)"
                    "VALUES (:clientID, :clientUsername, :clientPassword)");
        run.bindValue(":clientUsername",Client_username);
        run.bindValue(":clientPassword",Client_confirmpassword);
        run.exec();
        db.dbclose();
        this->hide();
        }


    else
    {
        qDebug()<<" cannot connect to mysql error";
        return ;
    }

}


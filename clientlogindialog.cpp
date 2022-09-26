#include "clientlogindialog.h"
#include "ui_clientlogindialog.h"
#include "clientpaneldialog.h"
#include <QMessageBox>
#include "global.h"
ClientloginDialog::ClientloginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientloginDialog)
{
    this->setWindowTitle("Client Login");
    ui->setupUi(this);
    ui->usernamelogin->setPlaceholderText("Enter Your Username");
    ui->passwordlogin->setPlaceholderText("Enter Your Password");
}

ClientloginDialog::~ClientloginDialog()
{
    delete ui;
}

void ClientloginDialog::on_pushButton_signup_clicked()
{
        this->hide();
        login_ui=new ClientsignupDialog(this);
        login_ui->show();
}


void ClientloginDialog::on_pushButton_Home_clicked()
{
    this->hide();
    parent();

}


void ClientloginDialog::on_pushButton_forgot_password_clicked()
{
    forget_password_ui = new ForgetPassword (this);
    forget_password_ui -> show();
}


void ClientloginDialog::on_pushButton_login_clicked()
{

    QString Client_username,Client_password;
    Client_username=ui->usernamelogin->text();
    Client_password=ui->passwordlogin->text();



        db.clientdbopen();
        QSqlQuery run;

        if(run.exec("SELECT * FROM clientlogin WHERE clientUsername='"+Client_username+"'  AND clientPassword= '"+Client_password+"'"))
        {
            int count=0;
            while(run.next())
            {
                client_ID=run.value(0).toString();
                qDebug()<<client_ID;
                count++;
            }
            if(count==1)
            {



                db.dbclose();
                this->hide();
                clientpanal_ui= new ClientpanelDialog(this);

                clientpanal_ui->show();

            }
            else if (count<1)
            {
                QMessageBox::warning(this,"Login Failed","Username or Password Incorrect");
            }
        }







}


#include "forgetpassword.h"
#include "ui_forgetpassword.h"

ForgetPassword::ForgetPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ForgetPassword)
{
    ui->setupUi(this);
    this->setWindowTitle("Forgot Password");
}

ForgetPassword::~ForgetPassword()
{
    delete ui;
}

void ForgetPassword::on_pushButton_check_clicked()
{
    QString email,phone,status,client_id,password;
    status=ui->lineEdit_email_phone->text();
    client_id=ui->lineEdit_clientId->text();
    db.clientdbopen();
    QSqlQuery run;
    run.prepare("select * from clientdetails where clientId='"+client_id+"' ");
    if(run.exec())
    {
        while (run.next())

        {
            email=run.value(2).toString();
            phone=run.value(3).toString();
        }

        db.dbclose();
    }
    if(status==email||status==phone)
    {

        db.clientdbopen();
        QSqlQuery query;
        query.prepare("select * from clientlogin where clientId='"+client_id+"'");
        if(query.exec())
        {
            while(query.next())
            {
                password=query.value(2).toString();

            }
            db.dbclose();
        }
        ui->label_password->setText("Your password is"+password);
    }
    else
    {
        ui->label_password->setText("Details Didn't match");
    }

}








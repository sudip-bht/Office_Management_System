#include "clientpaneldialog.h"
#include "ui_clientpaneldialog.h"
#include "global.h"
#include <QFileDialog>
#include <QMessageBox>
ClientpanelDialog::ClientpanelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientpanelDialog)
{
    this->setWindowTitle("Client Panel");
    ui->setupUi(this);
    ui->label_Client_id->setStyleSheet("color:black");
    ui->label_Client_Name->setStyleSheet("color:black");
    ui->lineEdit_Client_Email->setStyleSheet("color:black");
    ui->lineEdit_Client_phoneNo->setStyleSheet("color:black");

    db.clientdbopen();
    QString name,email,phone;
    QSqlQuery run;

    if(run.exec("SELECT * FROM clientdetails WHERE clientId='"+client_ID+"'"))
    {

        while(run.next())
        {
            name=run.value(1).toString();
            email=run.value(2).toString();
            phone=run.value(3).toString();

            ui->label_Client_Name->setText(name);
            ui->label_Client_id->setText(client_ID);
            ui->lineEdit_Client_Email->setText(email);
            ui->lineEdit_Client_phoneNo->setText(phone);
            db.dbclose();
        }
    set_tabel();











}
}
void ClientpanelDialog::set_tabel()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    db.clientdbopen();
    QSqlQuery  *run=new QSqlQuery();
    run->prepare("select slot,TokenNo,Review,Work from clientappointment where  clientId='"+client_ID+"' ");
    if(run->exec())
    {
        model->setQuery(*run);

        ui->tableView_appoinment->setModel(model);


    }
    else
    {
        qDebug()<<"Failed";
    }

}
ClientpanelDialog::~ClientpanelDialog()
{
    delete ui;
}


void ClientpanelDialog::on_pushButton_changeDetails_2_clicked()
{
    QString Email,Phone;

    Email=ui->lineEdit_Client_Email->text();
    Phone=ui->lineEdit_Client_phoneNo->text();

    db.clientdbopen();

    QSqlQuery run;
    run.prepare("update clientdetails set clientEmail='"+Email+"',clientPhone='"+Phone+"' where clientId='"+client_ID+"'");
    if(run.exec())
    {

        ui->label_status->setText("Changed addded");
        db.dbclose();

    }

}


void ClientpanelDialog::on_pushButton_BookAppoinment_clicked()
{
    booking_ui=new Booking(this);
    booking_ui->show();
}


void ClientpanelDialog::on_pushButton_AppoinmentDelete_clicked()
{
    cancellation_ui=new Cancellation(this);
    cancellation_ui->show();
    set_tabel();
}


void ClientpanelDialog::on_pushButton_refresh_clicked()
{
    set_tabel();
}




void ClientpanelDialog::on_pushButton_logout_clicked()
{
    this->hide();
    parent();
}


#include "booking.h"
#include "ui_booking.h"
#include "global.h"
Booking::Booking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Booking)
{
    this->setWindowTitle("Booking");
    ui->setupUi(this);
    comboslot();
    Availableslots();

}

Booking::~Booking()
{
    delete ui;
}
void Booking::Availableslots()
{
    db.clientdbopen();
    QSqlQuery run;
    run.prepare("select appointment_number,appointmentStatus from clientappointment");
    if(run.exec())
    {
        while(run.next())
        {
            QString available=run.value(1).toString();
            QString labelname= "lbl"+(run.value(0).toString());
            QLabel *ptr=this->findChild<QLabel*>(labelname);
            if(available.compare('N'))
            {
                ptr->setStyleSheet("QLabel{background-color:white;color:green;}");

            }
            else
            {
                ptr->setStyleSheet("QLabel{background-color:black;color:green;}");
            }
        }
        db.dbclose();
    }
    else
    {
        qDebug()<<"Query Failed";
    }
}
void Booking::comboslot()
{
    db.clientdbopen();
    QSqlQuery run;
    ui->cmbSlot->clear();
    run.prepare("select * from clientappointment where  appointmentStatus='Y'");
    if(run.exec())
    {
        while(run.next())
        {
            ui->cmbSlot->addItem(run.value(2).toString());
        }
        db.dbclose();
    }
    db.facilitiesdbopen();
    QSqlQuery run1;
    ui->cmbslot_facilities->clear();
    run1.prepare("select * from facilities_provided where Availability='Available'");
    if(run1.exec())
    {

        while(run1.next())
        {
            ui->cmbslot_facilities->addItem(run1.value(1).toString());
        }
        db.dbclose();

    }
}


void Booking::on_btnBook_clicked()
{
    QTime time;
    QString t;
    t=time.currentTime().toString();
    if(t<"24:00:00" && t>"03:00:00")
    {


    ui->lblInfo->setText("");
    QString slot=ui->cmbSlot->currentText();  //gets slot
    QString facilities=ui->cmbslot_facilities->currentText();
    QString Tokenno=QString::number((rand()%10000)+1);
    QString Date=QDate::currentDate().toString();
    QString status;
    db.clientdbopen();
    QSqlQuery run;
    run.prepare("select *from clientappointment where slot ='"+slot+"'");
    if(run.exec())
    {

        while(run.next())
        {
        status=run.value(3).toString();

        }
    }
    if(status=="Y")
    {
    run.prepare("update clientappointment set appointmentStatus='N' ,clientId='"+client_ID+"',Date='"+Date+"',TokenNo='"+Tokenno+"' ,Review='Unverified',Work='"+facilities+"' where slot='"+slot+"'");
    if(run.exec())
    {
    comboslot();
    Availableslots();

    ui->lblInfo->setText("Your Token NO is: "+Tokenno);
    }
    else
    {
        ui->lblInfo->setText("The slot is already booked ");
    }
    }
    }
    else
    {
        ui->lblInfo->setText("Booking is closed for the day");
    }
}





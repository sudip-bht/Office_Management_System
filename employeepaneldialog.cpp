#include "employeepaneldialog.h"
#include "global.h"
#include "ui_employeepaneldialog.h"
#include "connection.h"
#include "employeerecords.h"

EmployeepanelDialog::EmployeepanelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeepanelDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Employee Panel");
    setlabel();
    ui->label_Employee_id->setStyleSheet("color:black");
    ui->label_Employe_Name->setStyleSheet("color:black");
    ui->lineEdit_Employee_Email->setStyleSheet("color:black");
    ui->lineEdit_Employye_Conatct->setStyleSheet("color:black");
    ui->tableView_appoinment->setStyleSheet("color:black");
    db.employeedbopen();
    QString name,email,phone;
    QSqlQuery run;

    if(run.exec("SELECT * FROM employeedetails WHERE employeeId='"+Employee_ID+"'"))
    {

        while(run.next())
        {
            name=run.value(1).toString();
            email=run.value(2).toString();
            phone=run.value(5).toString();
            ui->label_Employe_Name->setText(name);
            ui->label_Employee_id->setText(Employee_ID);
            ui->lineEdit_Employee_Email->setText(email);
            ui->lineEdit_Employye_Conatct->setText(phone);

        }
    }
    db.dbclose();
    set_table();

     //db.dbclose();

}
void EmployeepanelDialog::set_table()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    db.clientdbopen();
    QSqlQuery  *query=new QSqlQuery();
    query->prepare("select clientId,slot,TokenNo,Date,Review, Work from clientappointment where  appointmentStatus='N' ");
    if(query->exec())
    {
        model->setQuery(*query);

        ui->tableView_appoinment->setModel(model);


    }

    else
    {
        qDebug()<<"Failed";
    }
}

EmployeepanelDialog::~EmployeepanelDialog()
{
    delete ui;
}
void EmployeepanelDialog::setlabel()
{
    db.employeedbopen();
    QString lastattendance;
    QString Date=QDate::currentDate().toString();
    QSqlQuery run;
    run.prepare("SELECT * FROM attendance WHERE employeeID='"+Employee_ID+"'");
    if(run.exec())
    {
        while(run.next())
        {
            lastattendance=run.value(2).toString();
        }

    }
    else
    {
        qDebug()<<"Error";
    }
    if(lastattendance==Date)
    {
        ui->attendance_label->setText("Attendance Done");

    }
    else
    {
        ui->attendance_label->setText("Attendance Not done");
    }
}
void EmployeepanelDialog::on_pushButton_changeDetails_clicked()
{
    QString Email,Phone,saved_Email,saved_Phone;
    Email=ui->lineEdit_Employee_Email->text();
    Phone=ui->lineEdit_Employye_Conatct->text();
    db.employeedbopen();

    QSqlQuery run;
    run.prepare("update employeedetails set employeeEmail='"+Email+"',employeePhone='"+Phone+"' where employeeId='"+Employee_ID+"'");
    if(run.exec())
    {

        ui->label_status->setText("Changed addded");
        db.dbclose();

    }



}


void EmployeepanelDialog::on_pushButton_Attendance_clicked()
{
    db.employeedbopen();
    QString Date=QDate::currentDate().toString();
    int attendance=0;
    QString last_attendance=0;
    QSqlQuery run;
    if(run.exec("SELECT * FROM attendance WHERE employeeID='"+Employee_ID+"'  "))
    {
        while(run.next())
        {
    attendance=run.value(1).toInt();
    last_attendance=run.value(2).toString();
        }
    }
    else
    {
        qDebug()<<"Error";
    }
    if (last_attendance != Date){
    int new_attendance=attendance+1;
    QString Attendance = QString::number(new_attendance);

    run.prepare("update attendance set attendance=  '"+Attendance+"',last_attendance='"+Date+"' where employeeId='"+Employee_ID+"'");
    if(run.exec())
    {

        ui->attendance_label->setText("Attendance Done");
        db.dbclose();

    }
    db.dbclose();
    }
    else
    {
        ui->attendance_label->setText("Attendance Already Done");
    }
}







void EmployeepanelDialog::on_tableView_appoinment_activated(const QModelIndex &index)
{
    val=ui->tableView_appoinment->model()->data(index).toString();

}


void EmployeepanelDialog::on_pushButton_cancelappointment_clicked()
{
    db.clientdbopen();
    QSqlQuery run;

    run.prepare("update clientappointment set appointmentStatus='Y' where tokenNo='"+val+"'");
    if(run.exec())
    {


            ui->lblInfo->setText("Appoinment Cancelled");
            set_table();
    }
            else
    {
            ui->lblInfo->setText("Appoinment Cannot be cancelled");
    }

}




void EmployeepanelDialog::on_pushButton_4_clicked()
{
    set_table();
}


void EmployeepanelDialog::on_pushButton_appointmentChecked_clicked()
{
    db.clientdbopen();
    QSqlQuery run;
    run.prepare("update clientappointment set review='Verfied' where tokenNo='"+val+"'");
    if(run.exec())
    {
        set_table();
    }
    else
    {
        set_table();
    }
}


void EmployeepanelDialog::on_pushButton_logout_clicked()
{
    this->hide();
    parent();
}


#include "adminpaneldailog.h"
#include "ui_adminpaneldailog.h"
#include "addemployee.h"
#include "ui_addemployee.h"
#include "connection.h"
#include <QMessageBox>

AddEmployee::AddEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEmployee)
{
    this->setWindowTitle("Add Employee");
    ui->setupUi(this);


}

AddEmployee::~AddEmployee()
{
    delete ui;
}

void AddEmployee::on_pushButton_add_clicked()
{

    QString employeeName,employeeEmail,employeePhone,employeeDepartment,employeePost,employeeUsername,employeePassword;
    employeeName=ui->lineEdit_Employee_Name->text();
    employeeEmail=ui->lineEdit_Employee_Email->text();
    employeePhone=ui->lineEdit_Employee_Phone->text();
    employeeUsername=ui->lineEdit_Employee_Username->text();
    employeePassword=ui->lineEdit_Employee_Password->text();
    employeeDepartment=ui->lineEdit_Employee_Department->text();
    employeePost=ui->lineEdit_Employee_Post->text();

    if(db.employeedbopen())
    {

    QSqlQuery run;
    run.prepare("INSERT INTO employeedetails (employeeId,employeeName,employeeEmail,employeePhone,employeeDepartment,employeePost)"
                "VALUES (:employeeId,:employeeName,:employeeEmail,:employeePhone,:employeeDepartment,:employeePost)");
    run.bindValue(":employeeName",employeeName);
    run.bindValue(":employeeEmail",employeeEmail);
    run.bindValue(":employeePhone",employeePhone);
    run.bindValue(":employeeDepartment",employeeDepartment);
    run.bindValue(":employeePost",employeePost);




     run.exec();
     db.dbclose();
    }

     //db.employeedbopen();
     if (db.employeedbopen())
     {
       QSqlQuery run;
     run.prepare("INSERT INTO employeelogin(employeeId,employeeUsername,employeePassword)"
                 "VALUES (:employeeId,:employeeUsername,:employeePassword)");
     run.bindValue(":employeeUsername",employeeUsername);

     run.bindValue(":employeePassword",employeePassword);

     run.exec();
     db.dbclose();

}
     if (db.employeedbopen())
     {
       QSqlQuery run;
     run.prepare("INSERT INTO attendance(employeeId,attendance,last_attendance)"
                 "VALUES (:employeeId,:attendance,:last_attendance)");
     run.bindValue(":attendance","0");

     run.bindValue(":last_attendance","0");

     run.exec();
     db.dbclose();

}
     this->hide();
}

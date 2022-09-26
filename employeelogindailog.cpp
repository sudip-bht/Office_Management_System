#include "employeelogindailog.h"
#include "ui_employeelogindailog.h"
#include "global.h"
#include <QMessageBox>
EmployeeloginDailog::EmployeeloginDailog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeloginDailog)
{
    ui->setupUi(this);
    this->setWindowTitle("Employee Login");
}

EmployeeloginDailog::~EmployeeloginDailog()
{
    delete ui;
}

void EmployeeloginDailog::on_pushButton_employee_login_clicked()

{

    QString Employee_username,Employee_password;
    Employee_username=ui->lineEdit_Employee_Username->text();
    Employee_password=ui->lineEdit_Employee_Password->text();



        db.employeedbopen();
        QSqlQuery run;
        if(Employee_username=="OMS"&&Employee_password=="1234")
        {
            this->hide();
            admin_ui=new AdminpanelDailog(this);
            admin_ui->show();
        }
        else if(run.exec("SELECT * FROM employeelogin WHERE employeeUsername='"+Employee_username+"'  AND employeePassword= '"+Employee_password+"'"))
        {
            int count=0;
            while(run.next())
            {
                Employee_ID=run.value(0).toString();

                count++;
            }
            if(count==1)
            {



                db.dbclose();
                this->hide();
                employeepanel_ui= new EmployeepanelDialog(this);
                employeepanel_ui->show();

            }

            else if (count<1)
            {
                QMessageBox::warning(this,"Login Failed","Username or Password Incorrect");
            }
        }







}

void EmployeeloginDailog::on_pushButton_2_clicked()
{
    this->hide();
    parent();
}


#include "adminpaneldailog.h"
#include "ui_adminpaneldailog.h"
#include "addemployee.h"
#include "employeerecords.h"
#include "clientrecords.h"

AdminpanelDailog::AdminpanelDailog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminpanelDailog)
{
    this->setWindowTitle("Admin");
    ui->setupUi(this);
    ui->lineEdit_Employee_ID->setPlaceholderText("Enter ID to begin Search");
    ui->lineEdit_Client_ID->setPlaceholderText("Enter ID to begin Search");
    employeerecords_ui = new EmployeeRecords(this);
    clientrecords_ui=new ClientRecords(this);
    comboslot();
}

AdminpanelDailog::~AdminpanelDailog()
{
    delete ui;
    delete employeerecords_ui;
    delete clientrecords_ui;
}


void AdminpanelDailog::comboslot()
{
    db.facilitiesdbopen();
    QSqlQuery run;
    run.prepare("select * from facilities_provided ");
    if(run.exec())
    {

        while(run.next())
        {
            ui->comboBox_services->addItem(run.value(1).toString());
        }

        db.dbclose();
    }
    db.facilitiesdbopen();
    QSqlQuery run1;
    run1.prepare("select * from notices");
    if(run1.exec())
    {

        while(run1.next())
        {
            ui->comboBox_notices->addItem(run1.value(1).toString());

        }
        db.dbclose();
    }
    db.facilitiesdbopen();
    QSqlQuery run2;
    run2.prepare("select * from facilities_provided where Availability='Available'");
    if(run2.exec())
    {
        while(run2.next())
        {
            ui->radioButton_avaliable->setChecked(0);
        }
    }
    else
    {
        ui->radioButton_unavailable->setChecked(1);
    }
    db.dbclose();
}
void AdminpanelDailog::on_pushButton_Search_Employee_clicked()
{
    QString name,email,phone,Employee_ID,Department,Post;
    Employee_ID=ui->lineEdit_Employee_ID->text();

    if(db.employeedbopen())
    {
    QSqlQuery run;

    if(run.exec("SELECT * FROM employeedetails WHERE employeeId='"+Employee_ID+"'"))
    {

        while(run.next())
        {
            name=run.value(1).toString();
            email=run.value(2).toString();
            phone=run.value(5).toString();
            Department=run.value(3).toString();
            Post=run.value(4).toString();

            ui->lineEdit_Employee_Name->setPlaceholderText(name);
            ui->lineEdit_Employee_ID->setPlaceholderText(Employee_ID);
            ui->lineEdit_Employee_Email->setPlaceholderText(email);
            ui->lineEdit_Employee_Contactno->setPlaceholderText(phone);
            ui->lineEdit_Employee_Depart->setPlaceholderText(Department);
            ui->lineEdit_Employee_Post->setPlaceholderText(Post);

            db.dbclose();
        }




    }
    }
}


void AdminpanelDailog::on_pushButton_Search_Client_clicked()
{
    QString name,email,phone,Client_ID;
    Client_ID=ui->lineEdit_Client_ID->text();
    db.clientdbopen();

    QSqlQuery run;

    if(run.exec("SELECT * FROM clientdetails WHERE clientId='"+Client_ID+"'"))
    {

        while(run.next())
        {
            name=run.value(1).toString();
            email=run.value(2).toString();
            phone=run.value(3).toString();


            ui->lineEdit_Client_Name->setPlaceholderText(name);
            ui->lineEdit_Client_ID->setPlaceholderText(Client_ID);
            ui->lineEdit_Client_Email->setPlaceholderText(email);
            ui->lineEdit_Client_PhoneNo->setPlaceholderText(phone);

            db.dbclose();
        }




    }

}


void AdminpanelDailog::on_pushButton_Delete_Employee_clicked()
{
    QString Id;
    Id=ui->lineEdit_Employee_ID->text();
    db.employeedbopen();
    if(db.employeedbopen())
    {
        int count=0;
    QSqlQuery run;
    run.prepare("delete from employeelogin where employeeId='"+Id+"'");
    if(run.exec())
    {
          count++;
    }
    QSqlQuery query;
    query.prepare("delete from employeedetails where employeeId='"+Id+"'");
    if(query.exec())
    {
            count++;
    }


    if(count==2)
    {
        ui->lblinfo->setText("Changes added");
    }
    else
    {
        ui->lblinfo->setText("Information Cannot be deleted");
    }
    db.dbclose();
    }

    AdminpanelDailog();


}




void AdminpanelDailog::on_pushButton_Delete_Client_clicked()
{

    QString Id;
    Id=ui->lineEdit_Client_ID->text();
    db.clientdbopen();
    if(db.clientdbopen())
    {
        int count=0;
    QSqlQuery run;
    run.prepare("delete from clientlogin where clientId='"+Id+"'");
    if(run.exec())
    {
          count++;
    }
    QSqlQuery query;
    query.prepare("delete from clientdetails where clientId='"+Id+"'");
    if(query.exec())
    {
           count++;
    }
    QSqlQuery query1;
    query1.prepare("delete from clientappoiment where clientId='"+Id+"'");
    if(query1.exec())
    {
        count++;
    }
    if(count==3)
    {
        ui->lblinfo_client->setText("Changes added");
    }
    else
    {
        ui->lblinfo_client->setText("Information Cannot be deleted");
    }
    db.dbclose();
    }
    AdminpanelDailog();
}



void AdminpanelDailog::on_pushButton_Add_Employee_clicked()
{

    addemployee_ui = new AddEmployee(this);
    addemployee_ui->show();
}

void AdminpanelDailog::on_pushButton_showEmployee_clicked()
{

    employeerecords_ui ->employedata();
    employeerecords_ui->show();

}





void AdminpanelDailog::on_pushButton_showClients_clicked()
{
    clientrecords_ui->clientdata();
    clientrecords_ui->show();
}


void AdminpanelDailog::on_pushButton_addfacilities_clicked()
{
    facilitiesadd_ui=new FacilitiesAdd();
    facilitiesadd_ui->show();

}


void AdminpanelDailog::on_comboBox_services_activated(int index)
{
    services=ui->comboBox_services->currentText();
}



void AdminpanelDailog::on_radioButton_avaliable_clicked()
{
    db.facilitiesdbopen();
    QSqlQuery run;
    run.prepare("update facilities_provided set Availability='Available' where Facilities='"+services+"'");
    if(run.exec())
    {
        AdminpanelDailog();
    }
    db.dbclose();

}


void AdminpanelDailog::on_radioButton_unavailable_clicked()
{
    db.facilitiesdbopen();
    QSqlQuery run;
    run.prepare("update facilities_provided set Availability='Unavailable' where Facilities='"+services+"'");
    if(run.exec())
    {

        ui->label_serviceupdated->setText("Service updated");
    }
    else
    {
        ui->label_serviceupdated->setText("Service Cannot be Updated");
    }
    db.dbclose();
}


void AdminpanelDailog::on_pushButton_addNotices_clicked()
{
    noticeadd_ui=new NoticeAdd();
    noticeadd_ui->show();
    this->hide();

}


void AdminpanelDailog::on_pushButton_Delete_clicked()
{
    QString heading=ui->comboBox_notices->currentText();
    db.facilitiesdbopen();
    QSqlQuery run;
    run.prepare("delete from notices where Heading ='"+heading+"' ");
    if(run.exec())
    {
        while(run.next())
        {
            ui->label_noticestatus->setText("Notice Deleted");
        }
    }
    else
    {
        ui->label_noticestatus->setText("Notice Cannot be deleted");

    }
    db.dbclose();
    comboslot();
}


#include "facilitiesadd.h"
#include "ui_facilitiesadd.h"

FacilitiesAdd::FacilitiesAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FacilitiesAdd)
{
    ui->setupUi(this);
    this->setWindowTitle("Facilities Add");
    comboslot();
}

FacilitiesAdd::~FacilitiesAdd()
{
    delete ui;
}
void FacilitiesAdd::comboslot()
{
    QSqlQuery run;
    ui->comboBox_Department->clear();
    run.prepare("select employeeDepartment from employeeDetails");
    if(run.exec())
    {


        ui->comboBox_Department->addItem(run.value(0).toString());

        db.dbclose();

    }
    else
    {
        qDebug()<<"Error";
    }
}
void FacilitiesAdd::on_buttonBox_accepted()
{
    db.facilitiesdbopen();
    QString facilities_name=ui->lineEdit_facilities->text();
    QString department=ui->comboBox_Department->currentText();
    QSqlQuery run;
    run.prepare("INSERT INTO facilities_provided ( SN, Facilities, Department, Availability)"
                  "VALUES ( :SN, :Facilities, :Department, :Availability)");
    run.bindValue(":Facilities",facilities_name);
    run.bindValue(":Department",department);
    run.bindValue(":Availability","Available");
    run.exec();

    QSqlQuery run1;
    run1.prepare("alter table documents_required add column "+facilities_name+" varchar(250) null" );
    run1.exec();
    QSqlQuery run2;
    QString requirements=ui->plainTextEdit_Requireddocuments->toPlainText();
    qDebug()<<requirements;
    run2.prepare("INSERT INTO documents_required ("+facilities_name+")"
                 "VALUES ('"+requirements+"')");
    run2.exec();
    db.dbclose();
}


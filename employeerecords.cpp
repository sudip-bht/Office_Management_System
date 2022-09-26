#include "employeerecords.h"
#include "ui_employeerecords.h"
#include "connection.h"
#include <QSqlTableModel>
EmployeeRecords::EmployeeRecords(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeRecords)
{
    ui->setupUi(this);
    this->setWindowTitle("Employee Record");
}


void EmployeeRecords :: employedata(){
    QSqlQueryModel *model = new QSqlQueryModel();
    db.employeedbopen();
    QSqlQuery* qry = new QSqlQuery(db.mydb);
    qry -> prepare("Select *from employeedetails order by employeeId");
    qry -> exec();

    model -> setQuery(*qry);

    ui->tableView->setModel(model);
    QSqlQueryModel *model1=new QSqlQueryModel();
    QSqlQuery  *run= new QSqlQuery(db.mydb);
     run->prepare("select attendance from attendance order by employeeId");
     run->exec();
     model1->setQuery(*run);
     ui->tableView_attendance->setModel(model1);

//db.dbclose();
}
EmployeeRecords::~EmployeeRecords()
{
    delete ui;
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientlogindialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Karalaya Home");
    ui->textBrowser_notices->setText("Double Click on notices to display the necessary notices");
    comboslot();
    employeedetails();
    requireddocuments();
    setList();


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::notice()
{
    db.facilitiesdbopen();
    QString Text,date,heading;
    QSqlQuery run;
    run.prepare("select * from notices where Heading='Important'");
    if(run.exec())
     {
        while(run.next())
        {
            date=run.value(0).toString();
            Text=run.value(2).toString();
            heading=run.value(1).toString();
        }
        ui->textBrowser_notices->setText(Text);

        db.dbclose();
    }
    else
    {
        ui->textBrowser_notices->setText("Notices Cannot be displayed");
    }

}
void MainWindow::comboslot()
{
    db.facilitiesdbopen();
    QSqlQuery run;
    ui->facilitiescomboBox->clear();
    run.prepare("select * from facilities_provided where Availability='Available'");
    if(run.exec())
    {

        while(run.next())
        {
            ui->facilitiescomboBox->addItem(run.value(1).toString());
        }
        db.dbclose();

    }
    db.employeedbopen();
    QSqlQuery query;
    ui->employessComboBox->clear();
    query.prepare("select employeeDepartment from employeedetails ");
    if(query.exec())
    {
        while(query.next())
        {
            ui->employessComboBox->addItem(query.value(0).toString());
        }

    }



}

void MainWindow::setList()
{
    notice();
    db.facilitiesdbopen();

    QSqlQuery *run = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    run->prepare("select Heading from notices");
    if(run->exec())
    {

        model->setQuery(*run);
        ui->listView_notices->setModel(model);

    }
    QString Date=QDate::currentDate().toString();
    QString Time=QTime::currentTime().toString();
    ui->label_day->setText(Date+","+Time);



}
void MainWindow::requireddocuments()
{
    QString facilities=ui->facilitiescomboBox->currentText();
    db.facilitiesdbopen();
    QSqlQuery *run = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    run->prepare("select "+facilities+" from documents_required");
    if(run->exec())
    {

        model->setQuery(*run);
        ui->facilitieslistview->setModel(model);

    }


}
void MainWindow::on_clientbutton_clicked()
{


    clientlogindialog = new ClientloginDialog(this);
    clientlogindialog -> show();
}




void MainWindow::on_employeebutton_clicked(){
    employee_ui=new EmployeeloginDailog(this);
    employee_ui->show();
}

void MainWindow::on_facilitiescomboBox_activated(int index)
{
    requireddocuments();



}
void MainWindow::on_employessComboBox_activated(int index)
{
    employeedetails();

}
void MainWindow::employeedetails()
{
    QString department=ui->employessComboBox->currentText();
    db.employeedbopen();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery* run = new QSqlQuery ;
    run->prepare("Select employeeName , employeeEmail ,Employeepost from employeedetails  where employeeDepartment='"+department+"'");
    if(run->exec())
    {
        model->setQuery(*run);

        ui->tableView_Employeedetails->setModel(model);
    }



}






void MainWindow::on_listView_notices_doubleClicked(const QModelIndex &index)
{

    Title=ui->listView_notices->model()->data(index).toString();
    noticdisplay_ui=new NoticeDisplay;
    noticdisplay_ui->show();
    db.dbclose();
    setList();

}



void MainWindow:: on_pushButton_refresh_clicked()
{
    notice();
    setList();



}












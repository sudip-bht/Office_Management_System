#include "noticeadd.h"
#include "ui_noticeadd.h"

NoticeAdd::NoticeAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoticeAdd)
{
    ui->setupUi(this);
    this->setWindowTitle("Add notices");
}

NoticeAdd::~NoticeAdd()
{
    delete ui;
}

void NoticeAdd::on_buttonBox_accepted()
{
    QString heading,notices,date;
    date=QDate::currentDate().toString();
    heading=ui->lineEdit_Heading->text();
    notices=ui->plainTextEdit_notices->toPlainText();
    db.facilitiesdbopen();
    QSqlQuery run;
    run.prepare("INSERT INTO notices(Dated, Heading, Content)"
                "VALUES (:Dated, :Heading, :Content)");
    run.bindValue(":Dated",date);
    run.bindValue(":Heading",heading);
    run.bindValue(":Content",notices);
    run.exec();
    db.dbclose();



}


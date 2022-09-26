#include "noticedisplay.h"
#include "ui_noticedisplay.h"

NoticeDisplay::NoticeDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NoticeDisplay)
{
    ui->setupUi(this);
    this->setWindowTitle("Notice");
    notice();
}

NoticeDisplay::~NoticeDisplay()
{
    delete ui;
}
void NoticeDisplay::notice()
{
    db.facilitiesdbopen();
    QString Text,date,heading;
    QSqlQuery run;
    run.prepare("select * from notices where Heading='"+Title+"'");
    if(run.exec())
     {
        while(run.next())
        {
            date=run.value(0).toString();
            Text=run.value(2).toString();
            heading=run.value(1).toString();
        }
        ui->textBrowser_notices->setText(Text);
        ui->label_date->setText(date);
        ui->label_Heading->setText(heading);
        db.dbclose();
    }
    else
    {
        ui->textBrowser_notices->setText("Notices Cannot be displayed");
    }

}

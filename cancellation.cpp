
#include "global.h"
#include "ui_cancellation.h"
#include "clientpaneldialog.h"

Cancellation::Cancellation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cancellation)
{
    this->setWindowTitle("Cancellation");
    ui->setupUi(this);
    comboslot();
}

Cancellation::~Cancellation()
{
    delete ui;

}
void Cancellation::comboslot()
{
    ui->cmbslot->clear();
    db.clientdbopen();
    QSqlQuery run;
    run.prepare("select * from clientappointment where appointmentStatus='N'");
    if(run.exec())
    {
        while(run.next())
        {
            ui->cmbslot->addItem(run.value(2).toString());

        }
        db.dbclose();
    }
}
void Cancellation::on_btnCancel_clicked()
{
    QString token_no,slot;
    token_no=ui->txtTokenNo->text();
    slot=ui->cmbslot->currentText();

    db.clientdbopen();
    QSqlQuery run;
    run.prepare("update clientappointment  set clientId='0' ,appointmentStatus='Y',Date='' where tokenNo='"+token_no+"' and clientId='"+client_ID+"'");
    if(run.exec())
    {

        this->hide();
        comboslot();
        ClientpanelDialog a;


    }
    else
    {
        ui->lblInfo->setText("Slot or Token Number didn't match");
    }

}





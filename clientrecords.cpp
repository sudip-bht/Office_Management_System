#include "clientrecords.h"
#include "ui_clientrecords.h"
#include "connection.h"
#include <QSqlTableModel>


ClientRecords::ClientRecords(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientRecords)
{
    this->setWindowTitle("Client Records");
    ui->setupUi(this);
}

void ClientRecords :: clientdata(){
    QSqlQueryModel *model = new QSqlQueryModel();
    db.clientdbopen();
    QSqlQuery* qry = new QSqlQuery(db.mydb);
    qry -> prepare("Select *from clientdetails order by clientId");
    qry -> exec();

    model -> setQuery(*qry);

    ui->tableView->setModel(model);

}


ClientRecords::~ClientRecords()
{
    delete ui;
}


#ifndef CLIENTRECORDS_H
#define CLIENTRECORDS_H

#include <QDialog>
#include "connection.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class ClientRecords;
}

class ClientRecords : public QDialog
{
    Q_OBJECT

public:
    explicit ClientRecords(QWidget *parent = nullptr);
    ~ClientRecords();
    void clientdata();
private:
    Ui::ClientRecords *ui;
    void getclientrecords();
    Connection db;
};

#endif // CLIENTRECORDS_H


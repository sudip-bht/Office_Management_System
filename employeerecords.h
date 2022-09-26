#ifndef EMPLOYEERECORDS_H
#define EMPLOYEERECORDS_H

#include <QDialog>
#include "connection.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class EmployeeRecords;
}

class EmployeeRecords : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeRecords(QWidget *parent = nullptr);
    ~EmployeeRecords();
    void employedata();

private:
    Ui::EmployeeRecords *ui;
    void getemployeerecords();
    Connection db;
};

#endif // EMPLOYEERECORDS_H

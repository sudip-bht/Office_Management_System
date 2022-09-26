#ifndef EMPLOYEELOGINDAILOG_H
#define EMPLOYEELOGINDAILOG_H

#include <QDialog>
#include <employeepaneldialog.h>
#include <adminpaneldailog.h>
#include "connection.h"
#include "global.h"
namespace Ui {
class EmployeeloginDailog;
}

class EmployeeloginDailog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeloginDailog(QWidget *parent = nullptr);
    ~EmployeeloginDailog();


private slots:
    void on_pushButton_employee_login_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EmployeeloginDailog *ui;
    EmployeepanelDialog *employeepanel_ui;
    AdminpanelDailog *admin_ui;
    QSqlTableModel *tableModel;
    Connection db;
};

#endif // EMPLOYEELOGINDAILOG_H

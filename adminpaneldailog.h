#ifndef ADMINPANELDAILOG_H
#define ADMINPANELDAILOG_H

#include <QMainWindow>
#include <connection.h>
#include <QMessageBox>
#include "addemployee.h"
#include "employeerecords.h"
#include "facilitiesadd.h"
#include "connection.h"
#include "clientrecords.h"
#include "noticeadd.h"
namespace Ui {
class AdminpanelDailog;
}

class AdminpanelDailog : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminpanelDailog(QWidget *parent = nullptr);
    ~AdminpanelDailog();
    QString services;

private slots:




    void on_pushButton_Search_Client_clicked();

    void on_pushButton_Search_Employee_clicked();

    void on_pushButton_Delete_Employee_clicked();

    void on_pushButton_Add_Employee_clicked();

    void on_pushButton_Delete_Client_clicked();







    void on_pushButton_showEmployee_clicked();

    void on_pushButton_showClients_clicked();


    void comboslot();
    void on_pushButton_addfacilities_clicked();

    void on_comboBox_services_activated(int index);

    void on_radioButton_avaliable_clicked();

    void on_radioButton_unavailable_clicked();

    void on_pushButton_addNotices_clicked();

    void on_pushButton_Delete_clicked();

private:
    Ui::AdminpanelDailog *ui;
    Connection db;

    AddEmployee *addemployee_ui;
    EmployeeRecords *employeerecords_ui;
    ClientRecords *clientrecords_ui;
    FacilitiesAdd *facilitiesadd_ui;
    NoticeAdd *noticeadd_ui;

};

#endif // ADMINPANELDAILOG_H

#ifndef EMPLOYEEPANELDIALOG_H
#define EMPLOYEEPANELDIALOG_H
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDialog>
#include "connection.h"

namespace Ui {
class EmployeepanelDialog;
}

class EmployeepanelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeepanelDialog(QWidget *parent = nullptr);
    ~EmployeepanelDialog();

private slots:
    void on_pushButton_changeDetails_clicked();

    void on_pushButton_Attendance_clicked();



    void on_pushButton_cancelappointment_clicked();

    void on_tableView_appoinment_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_appointmentChecked_clicked();

    void on_pushButton_logout_clicked();
    void setlabel();
private:
    QString val;
    Ui::EmployeepanelDialog *ui;
    QSqlTableModel *tabelModel;
    Connection db;
    void set_table();
};

#endif // EMPLOYEEPANELDIALOG_H

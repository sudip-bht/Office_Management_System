#ifndef ADDEMPLOYEE_H
#define ADDEMPLOYEE_H

#include <QMainWindow>
#include <QDialog>
#include <QMessageBox>
#include "connection.h"
namespace Ui {
class AddEmployee;
}

class AddEmployee : public QDialog
{
    Q_OBJECT

public:
    explicit AddEmployee(QWidget *parent = nullptr);
    ~AddEmployee();

private slots:
    void on_pushButton_add_clicked();

private:

    Ui::AddEmployee *ui;

    Connection db;


};

#endif // ADDEMPLOYEE_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "clientlogindialog.h"
#include "employeelogindailog.h"
#include "facilitiesadd.h"
#include "connection.h"
#include "global.h"
#include "noticedisplay.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QTimer timer;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_clientbutton_clicked();
    void comboslot();
    void on_employeebutton_clicked();
    void on_employessComboBox_activated(int index);
    void on_facilitiescomboBox_activated(int index);
    void requireddocuments();
    void employeedetails();
    void setList();
    void on_listView_notices_doubleClicked(const QModelIndex &index);
    void notice();
    void on_pushButton_refresh_clicked();






private:
    Ui::MainWindow *ui;
    ClientloginDialog *clientlogindialog;
    EmployeeloginDailog *employee_ui;
    NoticeDisplay *noticdisplay_ui;
    Connection db;




};


#endif // MAINWINDOW_H

#ifndef CLIENTPANELDIALOG_H
#define CLIENTPANELDIALOG_H
#include "connection.h"
#include "booking.h"
#include "cancellation.h"
#include <QDialog>
//#include "clientlogindialog.h"

namespace Ui {
class ClientpanelDialog;
}

class ClientpanelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientpanelDialog(QWidget *parent = nullptr);
    ~ClientpanelDialog();

private slots:
    void on_pushButton_changeDetails_2_clicked();

    void on_pushButton_BookAppoinment_clicked();

    void on_pushButton_AppoinmentDelete_clicked();


    void on_pushButton_refresh_clicked();

    void on_pushButton_logout_clicked();

public:
    Ui::ClientpanelDialog *ui;
    Connection db;
    Booking *booking_ui;
    Cancellation *cancellation_ui;
    void set_tabel();

};

#endif // CLIENTPANELDIALOG_H

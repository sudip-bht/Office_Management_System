#ifndef BOOKING_H
#define BOOKING_H

#include <QDialog>
#include <QTime>

#include "connection.h"
namespace Ui {
class Booking;
}

class Booking : public QDialog
{
    Q_OBJECT

public:
    explicit Booking(QWidget *parent = nullptr);
    ~Booking();

private slots:

    void Availableslots();
    void on_btnBook_clicked();
    void comboslot();

private:
    Ui::Booking *ui;

    Connection db;
};

#endif // BOOKING_H

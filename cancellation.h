#ifndef CANCELLATION_H
#define CANCELLATION_H

#include <QDialog>
#include <connection.h>

namespace Ui {
class Cancellation;
}

class Cancellation : public QDialog
{
    Q_OBJECT


public:
    explicit Cancellation(QWidget *parent = nullptr);
    ~Cancellation();

private slots:
    void on_btnCancel_clicked();


private:
    Ui::Cancellation *ui;
    Connection db;
    void comboslot();

};

#endif // CANCELLATION_H

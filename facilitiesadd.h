#ifndef FACILITIESADD_H
#define FACILITIESADD_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class FacilitiesAdd;
}

class FacilitiesAdd : public QDialog
{
    Q_OBJECT

public:
    explicit FacilitiesAdd(QWidget *parent = nullptr);
    ~FacilitiesAdd();

private slots:
    void on_buttonBox_accepted();
    void comboslot();
private:
    Ui::FacilitiesAdd *ui;
    Connection db;
};

#endif // FACILITIESADD_H

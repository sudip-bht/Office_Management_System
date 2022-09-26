#ifndef NOTICEADD_H
#define NOTICEADD_H

#include <QDialog>
#include <connection.h>
namespace Ui {
class NoticeAdd;
}

class NoticeAdd : public QDialog
{
    Q_OBJECT

public:
    explicit NoticeAdd(QWidget *parent = nullptr);
    ~NoticeAdd();

private slots:
    void on_buttonBox_accepted();


private:
    Ui::NoticeAdd *ui;
    Connection db;
};

#endif // NOTICEADD_H

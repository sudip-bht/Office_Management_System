#ifndef NOTICEDISPLAY_H
#define NOTICEDISPLAY_H

#include <QWidget>
#include "connection.h"
#include "global.h"
namespace Ui {
class NoticeDisplay;
}

class NoticeDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit NoticeDisplay(QWidget *parent = nullptr);
    ~NoticeDisplay();
    void notice();
private:
    Ui::NoticeDisplay *ui;
    Connection db;
};

#endif // NOTICEDISPLAY_H

QT       += core gui
QT  += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addemployee.cpp \
    adminpaneldailog.cpp \
    booking.cpp \
    cancellation.cpp \
    clientlogindialog.cpp \
    clientpaneldialog.cpp \
    clientrecords.cpp \
    clientsignupdialog.cpp \
    employeelogindailog.cpp \
    employeepaneldialog.cpp \
    employeerecords.cpp \
    facilitiesadd.cpp \
    forgetpassword.cpp \
    global.cpp \
    main.cpp \
    mainwindow.cpp \
    noticeadd.cpp \
    noticedisplay.cpp

HEADERS += \
    addemployee.h \
    adminpaneldailog.h \
    booking.h \
    cancellation.h \
    clientlogindialog.h \
    clientpaneldialog.h \
    clientrecords.h \
    clientsignupdialog.h \
    connection.h \
    employeelogindailog.h \
    employeepaneldialog.h \
    employeerecords.h \
    facilitiesadd.h \
    forgetpassword.h \
    global.h \
    mainwindow.h \
    noticeadd.h \
    noticedisplay.h

FORMS += \
    addemployee.ui \
    adminpaneldailog.ui \
    booking.ui \
    cancellation.ui \
    clientlogindialog.ui \
    clientpaneldialog.ui \
    clientrecords.ui \
    clientsignupdialog.ui \
    employeelogindailog.ui \
    employeepaneldialog.ui \
    employeerecords.ui \
    facilitiesadd.ui \
    forgetpassword.ui \
    mainwindow.ui \
    noticeadd.ui \
    noticedisplay.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    Resourceslogin.qrc

DISTFILES += \
    Images/refresh.png

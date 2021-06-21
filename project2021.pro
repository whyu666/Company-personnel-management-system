QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add.cpp \
    add_manager.cpp \
    add_salesman.cpp \
    add_salesmanager.cpp \
    add_technician.cpp \
    combine.cpp \
    del.cpp \
    main.cpp \
    manager.cpp \
    output.cpp \
    person.cpp \
    salesman.cpp \
    salesmanager.cpp \
    save.cpp \
    search.cpp \
    technician.cpp \
    widget.cpp

HEADERS += \
    add.h \
    add_manager.h \
    add_salesman.h \
    add_salesmanager.h \
    add_technician.h \
    combine.h \
    del.h \
    manager.h \
    output.h \
    person.h \
    salesman.h \
    salesmanager.h \
    save.h \
    search.h \
    technician.h \
    widget.h

FORMS += \
    add.ui \
    add_manager.ui \
    add_salesman.ui \
    add_salesmanager.ui \
    add_technician.ui \
    del.ui \
    output.ui \
    save.ui \
    search.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

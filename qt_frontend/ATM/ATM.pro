QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    engineatm.cpp \
    main.cpp \
    mainwindow.cpp \
    nosto.cpp \
    pin.cpp \
    saldo.cpp \
    tilisiirto.cpp \
    tilitapahtumat.cpp \
    valikko.cpp

HEADERS += \
    engineatm.h \
    mainwindow.h \
    nosto.h \
    pin.h \
    saldo.h \
    tilisiirto.h \
    tilitapahtumat.h \
    valikko.h

FORMS += \
    mainwindow.ui \
    nosto.ui \
    pin.ui \
    saldo.ui \
    tilisiirto.ui \
    tilitapahtumat.ui \
    valikko.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



win32: LIBS += -L$$PWD/../build-DLLSerialPort-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/debug/ -lDLLSerialPort

INCLUDEPATH += $$PWD/../DLLSerialPort
DEPENDPATH += $$PWD/../DLLSerialPort

win32: LIBS += -L$$PWD/../build-DLLRestAPI-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/debug/ -lDLLRestAPI

INCLUDEPATH += $$PWD/../DLLRestAPI
DEPENDPATH += $$PWD/../DLLRestAPI

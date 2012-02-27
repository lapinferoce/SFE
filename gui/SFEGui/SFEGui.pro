#-------------------------------------------------
#
# Project created by QtCreator 2012-02-27T11:39:44
#
#-------------------------------------------------

QT       += core gui network

TARGET = SFEGui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    client.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L/opt/lib/ -lSFEProtocole
else:win32:CONFIG(debug, debug|release): LIBS += -L/opt/lib/ -lSFEProtocole
else:symbian: LIBS += -lSFEProtocole
else:unix: LIBS += -L/opt/lib/ -lSFEProtocole

INCLUDEPATH += /opt/include/
DEPENDPATH += /opt/include/

CONFIG += debug

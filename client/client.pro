######################################################################
# Automatically generated by qmake (2.01a) dim. janv. 1 21:08:20 2012
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

QT += network


# Input
HEADERS += Client.h
SOURCES += Client.cpp main.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../SFEProtocole/release/ -lSFEProtocole
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../SFEProtocole/debug/ -lSFEProtocole
else:symbian: LIBS += -lSFEProtocole
else:unix: LIBS += -L$$PWD/../SFEProtocole -lSFEProtocole

INCLUDEPATH += $$PWD/../SFEProtocole
DEPENDPATH += $$PWD/../SFEProtocole

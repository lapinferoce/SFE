#-------------------------------------------------
#
# Project created by QtCreator 2012-01-31T00:05:46
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = SFEProtocole
TEMPLATE = lib

DEFINES += SFEPROTOCOLE_LIBRARY

SOURCES += sfeprotocole.cpp \
    sfequery.cpp \
    sfefilequery.cpp \
    sfefilelistquery.cpp \
    sfenotypequery.cpp


HEADERS += sfeprotocole.h\
        SFEProtocole_global.h \
    sfequery.h \
    sfefilequery.h \
    sfefilelistquery.h \
    sfenotypequery.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE2A3B673
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = SFEProtocole.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

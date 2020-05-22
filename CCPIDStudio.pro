#-------------------------------------------------
#
# Project created by QtCreator 2020-05-22T10:28:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CCPIDStudio
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    lydg.cpp \
    pointset.cpp \
    startwidget.cpp \
    ccpidglobal.cpp

HEADERS += \
        widget.h \
    ciportal.h \
    fileportal.h \
    lydg.h \
    pointset.h \
    startwidget.h \
    ccpidglobal.h

#LIBS += -L$$PWD/CIPortal.lib
#LIBS += -L$$PWD/FilePortal.lib
#unix:LIBS += -L/usr/local/lib -lmath
#win32:LIBS += c:/mylibs/math.lib

LIBS += -L$$PWD/./ -lCIPortal
LIBS += -L$$PWD/./ -lFilePortal

FORMS += \
    test/DlgReference.ui






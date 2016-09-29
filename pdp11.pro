#-------------------------------------------------
#
# Project created by QtCreator 2016-09-28T17:45:18
#
#-------------------------------------------------

CONFIG += c++11

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pdp11
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vcpu.cpp \
    screen.cpp \
    disasmodel.cpp \
    clickablelabel.cpp \
    aspectratiowidget.cpp \
    instructions.cpp \
    instructiontable.cpp

HEADERS  += mainwindow.h \
    vcpu.h \
    screen.h \
    disasmodel.h \
    clickablelabel.h \
    aspectratiowidget.h
    instructions.h

FORMS    += mainwindow.ui
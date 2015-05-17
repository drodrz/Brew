#-------------------------------------------------
#
# Project created by QtCreator 2015-05-14T20:48:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Brew
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fermentable.cpp \
    fermentablemodel.cpp

HEADERS  += mainwindow.h \
    fermentable.h \
    fermentablemodel.h

FORMS    += mainwindow.ui

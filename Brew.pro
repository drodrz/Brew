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
    fermentablemodel.cpp \
    fermentable.cpp \
    hop.cpp \
    hopmodel.cpp \
    yeastmodel.cpp \
    yeast.cpp \
    recipe.cpp

HEADERS  += mainwindow.h \
    fermentablemodel.h \
    fermentable.h \
    hop.h \
    hopmodel.h \
    yeastmodel.h \
    yeast.h \
    recipe.h

FORMS    += mainwindow.ui

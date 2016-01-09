#-------------------------------------------------
#
# Project created by QtCreator 2016-01-06T14:43:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DelegateDemo
TEMPLATE = app


SOURCES += main.cpp\
        deletedemo.cpp \
    itemdelegate.cpp

HEADERS  += deletedemo.h \
    itemdelegate.h

FORMS    += deletedemo.ui

RESOURCES += \
    image.qrc

#-------------------------------------------------
#
# Project created by QtCreator 2015-12-11T10:42:18
#
#-------------------------------------------------

QT       += core sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Skil3
TEMPLATE = app
CONFIG += console c++11

SOURCES += main.cpp\
        MainWindow/mainwindow.cpp \
    Data/computers.cpp \
    Data/scientists.cpp \
    Data/data.cpp \
    Domain/domain.cpp

HEADERS  += MainWindow/mainwindow.h \
    Data/computers.h \
    Data/scientists.h \
    Data/data.h \
    Domain/domain.h

FORMS    += mainwindow.ui

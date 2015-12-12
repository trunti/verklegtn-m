#-------------------------------------------------
#
# Project created by QtCreator 2015-12-12T10:36:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Skil3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Scientists/scientists.cpp \
    Scientistrepositories/scientistsrepositories.cpp \
    Scientistservice/scientistservice.cpp \
    Computers/computers.cpp \
    Computersrepositories/computersrepositories.cpp \
    Computerservice/computerservice.cpp

HEADERS  += mainwindow.h \
    Scientists/scientists.h \
    Scientistrepositories/scientistsrepositories.h \
    Scientistservice/scientistservice.h \
    Computers/computers.h \
    Computersrepositories/computersrepositories.h \
    Computerservice/computerservice.h

FORMS    += mainwindow.ui

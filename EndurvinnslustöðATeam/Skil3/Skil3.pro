#-------------------------------------------------
#
# Project created by QtCreator 2015-12-12T10:36:16
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Skil3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Models/scientists.cpp \
    Repositories/scientistsrepositories.cpp \
    Services/scientistservice.cpp \
    Models/computers.cpp \
    Repositories/computersrepositories.cpp \
    Services/computerservice.cpp \
    Ui/scientistsdisplay.cpp \
    Ui/computerdisplay.cpp \
    Ui/random.cpp \
    Ui/addscientist.cpp \
    Ui/addcomputer.cpp \
    Repositories/linkrepository.cpp \
    Services/linkservice.cpp \
    Ui/linktogether.cpp

HEADERS  += mainwindow.h \
    Models/scientists.h \
    Repositories/scientistsrepositories.h \
    Services/scientistservice.h \
    Models/computers.h \
    Repositories/computersrepositories.h \
    Services/computerservice.h \
    Ui/scientistsdisplay.h \
    Ui/computerdisplay.h \
    Ui/random.h \
    Ui/addscientist.h \
    Ui/addcomputer.h \
    Repositories/linkrepository.h \
    Services/linkservice.h \
    Ui/linktogether.h

FORMS    += mainwindow.ui \
    Ui/scientistsdisplay.ui \
    Ui/computerdisplay.ui \
    Ui/random.ui \
    Ui/addscientist.ui \
    Ui/addcomputer.ui \
    Ui/linktogether.ui

RESOURCES += \
    resource.qrc

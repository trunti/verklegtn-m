QT += core sql
QT -= gui

TARGET = Verklegtvika2
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    data/data.cpp \
    ui/ui.cpp \
    domain/domain.cpp \
    data/computers.cpp \
    data/scientists.cpp

HEADERS += \
    data/data.h \
    ui/ui.h \
    domain/domain.h \
    data/computers.h \
    data/scientists.h


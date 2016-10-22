#-------------------------------------------------
#
# Project created by QtCreator 2016-10-17T15:57:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DungeonGenerator
TEMPLATE = app


SOURCES += main.cpp \
    dungeongenerator.cpp \
    tile.cpp

HEADERS  += \
    dungeongenerator.h \
    tile.h

FORMS    += mainwindow.ui

Debug:DESTDIR = debug
Debug:OBJECTS_DIR = debug/.obj
Debug:MOC_DIR = debug/.moc
Debug:RCC_DIR = debug/.rcc
Debug:UI_DIR = debug/.ui

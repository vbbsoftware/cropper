#-------------------------------------------------
#
# Project created by QtCreator 2011-08-25T10:51:30
#
#-------------------------------------------------

QT       += core gui

TARGET = cropper-gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        cropper.cpp \
    command.cpp \
    resize.cpp \
    scale.cpp \
    commandexception.cpp

HEADERS  += mainwindow.h\
            cropper.h \
    command.h \
    resize.h \
    scale.h \
    commandexception.h

FORMS    += mainwindow.ui

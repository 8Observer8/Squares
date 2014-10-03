#-------------------------------------------------
#
# Project created by QtCreator 2014-10-02T10:28:24
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Square
TEMPLATE = app


SOURCES += main.cpp\
        Dialog.cpp \
    Scene.cpp \
    Square.cpp \
    Point.cpp \
    freeFunctions.cpp

HEADERS  += Dialog.h \
    Scene.h \
    Square.h \
    Point.h \
    freeFunctions.h

FORMS    += Dialog.ui

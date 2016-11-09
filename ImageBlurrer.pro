#-------------------------------------------------
#
# Project created by QtCreator 2016-11-08T10:43:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageBlurrer
TEMPLATE = app


SOURCES += main.cpp\
        mainblurrer.cpp \
    imagingthread.cpp

HEADERS  += mainblurrer.h \
    helper.h \
    imagingthread.h

RC_ICONS = my_icon.ico

RESOURCES += \
    res.qrc

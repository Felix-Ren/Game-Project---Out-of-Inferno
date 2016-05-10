#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T14:47:42
#
#-------------------------------------------------

QT       += core gui \
    multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HW8
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    b3.cpp \
    b5.cpp \
    playerinfo.cpp \
    diedialog.cpp \
    b4.cpp \
    debug.cpp \
    instructiondialog.cpp \
    successdialog.cpp

HEADERS  += mainwindow.h \
    b3.h \
    b5.h \
    debug.h \
    playerinfo.h \
    diedialog.h \
    b4.h \
    instructiondialog.h \
    successdialog.h

FORMS    += mainwindow.ui \
    b3.ui \
    b5.ui \
    diedialog.ui \
    b4.ui \
    instructiondialog.ui \
    successdialog.ui

RESOURCES += \
    background_pic.qrc \
    sound.qrc

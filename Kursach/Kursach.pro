#-------------------------------------------------
#
# Project created by QtCreator 2017-12-10T18:51:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kursach
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    mainmenu.cpp \
    saves.cpp \
    game.cpp \
    algorithm.cpp \
    press_to_save.cpp

HEADERS += \
    mainmenu.h \
    saves.h \
    game.h \
    algorithm.h \
    press_to_save.h

FORMS += \
    mainmenu.ui \
    saves.ui \
    game.ui \
    press_to_save.ui
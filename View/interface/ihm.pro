#-------------------------------------------------
#
# Project created by QtCreator 2018-03-20T22:29:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ihm
TEMPLATE = app


SOURCES += main.cpp      \
        mainwindow.cpp   \
        computer.cpp     \
        online.cpp       \
        playernumber.cpp \
        card.cpp         \
        game.cpp         \
        information.cpp

HEADERS  += mainwindow.h \
    computer.h \
    online.h \
    playernumber.h \
    card.h \
    game.h \
    utils.h \
    information.h

FORMS    += mainwindow.ui \
    computer.ui \
    online.ui \
    playernumber.ui \
    game.ui \
    information.ui

RESOURCES += \
    images.qrc

DISTFILES +=

#-------------------------------------------------
#
# Project created by QtCreator 2018-03-20T22:29:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ihm
TEMPLATE = app


SOURCES += main.cpp                     \
        mainwindow.cpp                  \
        computer.cpp                    \
        online.cpp                      \
        playernumber.cpp                \
        card.cpp                        \
        game.cpp                        \
        information.cpp                 \
        View.cpp                        \
        Presentation.cpp                \

HEADERS  += mainwindow.h \
    computer.h           \
    online.h             \
    playernumber.h       \
    card.h               \
    game.h               \
    utils.h              \
    information.h        \
    View.h               \
    Presentation.h       \

FORMS    += mainwindow.ui \
    computer.ui           \
    online.ui             \
    playernumber.ui       \
    game.ui               \
    information.ui

RESOURCES += \
    images.qrc

DISTFILES +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build/release/ -lNetwork
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build/debug/ -lNetwork
else:unix: LIBS += -L$$PWD/../../build/ -lNetwork

INCLUDEPATH += $$PWD/../../build
DEPENDPATH += $$PWD/../../build

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build/release/ -lSerialize
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build/debug/ -lSerialize
else:unix: LIBS += -L$$PWD/../../build/ -lSerialize

INCLUDEPATH += $$PWD/../../build
DEPENDPATH += $$PWD/../../build

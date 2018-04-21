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
        utils.cpp                \
		../../Network/IConnection.cpp   \
		../../Network/Network.cpp       \
		../../Network/TCPClientConnection.cpp \
		../../Network/TCPServerConnection.cpp \
		../../Msg/TypesTools.cpp \
		../../Msg/Serializer.cpp \
		../../Msg/GenericMsg.cpp \
		../../Msg/Deserializer.cpp \
                ../../GameCommon/TypesSerializers.cpp

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
    computer.ui \
    online.ui \
    playernumber.ui \
    game.ui \
    information.ui

RESOURCES += \
    images.qrc

DISTFILES +=

TRANSLATIONS = l10n/translations_fr_FR.ts \
			   l10n/translations_en_EN.ts

CONFIG += c++11

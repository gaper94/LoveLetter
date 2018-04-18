/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QLabel *userLabel;
    QLabel *scoreLabel;

    void setupUi(QDialog *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QStringLiteral("Game"));
        Game->resize(960, 640);
        Game->setMinimumSize(QSize(960, 640));
        Game->setMaximumSize(QSize(960, 640));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ressources/game_icon.png"), QSize(), QIcon::Normal, QIcon::On);
        Game->setWindowIcon(icon);
        Game->setStyleSheet(QLatin1String("background-image: url(:/ressources/bgrd.jpg); \n"
"background-position: center; \n"
"background-repeat: repeat-xy;"));
        userLabel = new QLabel(Game);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        userLabel->setGeometry(QRect(400, 580, 150, 50));
        userLabel->setMinimumSize(QSize(150, 50));
        userLabel->setMaximumSize(QSize(150, 50));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        userLabel->setFont(font);
        userLabel->setStyleSheet(QStringLiteral("background-color: rgb(32, 74, 135);"));
        userLabel->setAlignment(Qt::AlignCenter);
        scoreLabel = new QLabel(Game);
        scoreLabel->setObjectName(QStringLiteral("scoreLabel"));
        scoreLabel->setGeometry(QRect(0, 590, 350, 50));
        scoreLabel->setMinimumSize(QSize(350, 50));
        scoreLabel->setMaximumSize(QSize(350, 50));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        scoreLabel->setFont(font1);
        scoreLabel->setStyleSheet(QStringLiteral("background-color: rgb(32, 74, 135);"));
        scoreLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QDialog *Game)
    {
        Game->setWindowTitle(QApplication::translate("Game", "Love Letter", Q_NULLPTR));
        userLabel->setText(QApplication::translate("Game", "TextLabel", Q_NULLPTR));
        scoreLabel->setText(QApplication::translate("Game", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H

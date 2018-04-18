/********************************************************************************
** Form generated from reading UI file 'playernumber.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERNUMBER_H
#define UI_PLAYERNUMBER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerNumber
{
public:
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *twoPlayersButton;
    QPushButton *threePlayersButton;
    QPushButton *fourPlayersButton;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *computerButton;
    QPushButton *onlineButton;

    void setupUi(QDialog *PlayerNumber)
    {
        if (PlayerNumber->objectName().isEmpty())
            PlayerNumber->setObjectName(QStringLiteral("PlayerNumber"));
        PlayerNumber->resize(960, 640);
        PlayerNumber->setMinimumSize(QSize(960, 640));
        PlayerNumber->setMaximumSize(QSize(960, 640));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ressources/game_icon.png"), QSize(), QIcon::Normal, QIcon::On);
        PlayerNumber->setWindowIcon(icon);
        PlayerNumber->setStyleSheet(QLatin1String("/*\n"
"background-color: rgb(81, 60, 117);\n"
"*/"));
        label = new QLabel(PlayerNumber);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 960, 75));
        label->setMinimumSize(QSize(960, 75));
        label->setMaximumSize(QSize(960, 75));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: white;"));
        label->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(PlayerNumber);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(40, 130, 881, 131));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        twoPlayersButton = new QPushButton(horizontalLayoutWidget);
        twoPlayersButton->setObjectName(QStringLiteral("twoPlayersButton"));
        twoPlayersButton->setMinimumSize(QSize(250, 100));
        twoPlayersButton->setMaximumSize(QSize(250, 100));
        QFont font1;
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setWeight(75);
        twoPlayersButton->setFont(font1);
        twoPlayersButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255,229,232);\n"
"	color: rgb(227,91,120);\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"	background-color: rgb(227,91,120);\n"
"	color: rgb(255,229,232);\n"
"}"));
        twoPlayersButton->setCheckable(true);
        twoPlayersButton->setChecked(false);
        twoPlayersButton->setAutoRepeat(false);

        horizontalLayout->addWidget(twoPlayersButton);

        threePlayersButton = new QPushButton(horizontalLayoutWidget);
        threePlayersButton->setObjectName(QStringLiteral("threePlayersButton"));
        threePlayersButton->setMinimumSize(QSize(250, 100));
        threePlayersButton->setMaximumSize(QSize(250, 100));
        threePlayersButton->setFont(font1);
        threePlayersButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255,229,232);\n"
"	color: rgb(227,91,120);\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"	background-color: rgb(227,91,120);\n"
"	color: rgb(255,229,232);\n"
"}"));
        threePlayersButton->setCheckable(true);

        horizontalLayout->addWidget(threePlayersButton);

        fourPlayersButton = new QPushButton(horizontalLayoutWidget);
        fourPlayersButton->setObjectName(QStringLiteral("fourPlayersButton"));
        fourPlayersButton->setMinimumSize(QSize(250, 100));
        fourPlayersButton->setMaximumSize(QSize(250, 100));
        fourPlayersButton->setFont(font1);
        fourPlayersButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255,229,232);\n"
"	color: rgb(227,91,120);\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"	background-color: rgb(227,91,120);\n"
"	color: rgb(255,229,232);\n"
"}"));
        fourPlayersButton->setCheckable(true);
        fourPlayersButton->setChecked(false);

        horizontalLayout->addWidget(fourPlayersButton);

        label_2 = new QLabel(PlayerNumber);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 320, 960, 75));
        label_2->setMinimumSize(QSize(960, 75));
        label_2->setMaximumSize(QSize(960, 75));
        QFont font2;
        font2.setPointSize(30);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_2->setStyleSheet(QLatin1String("color: white;\n"
""));
        label_2->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_2 = new QWidget(PlayerNumber);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(160, 430, 631, 131));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        computerButton = new QPushButton(horizontalLayoutWidget_2);
        computerButton->setObjectName(QStringLiteral("computerButton"));
        computerButton->setMinimumSize(QSize(300, 100));
        computerButton->setMaximumSize(QSize(300, 100));
        computerButton->setFont(font2);
        computerButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255,229,232);\n"
"	color: rgb(227,91,120);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	background-color: rgb(194,165,171);\n"
"	color: rgb(79,63,66);\n"
"}"));
        computerButton->setCheckable(true);

        horizontalLayout_2->addWidget(computerButton);

        onlineButton = new QPushButton(horizontalLayoutWidget_2);
        onlineButton->setObjectName(QStringLiteral("onlineButton"));
        onlineButton->setMinimumSize(QSize(300, 100));
        onlineButton->setMaximumSize(QSize(300, 100));
        onlineButton->setFont(font2);
        onlineButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255,229,232);\n"
"	color: rgb(227,91,120);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	background-color: rgb(194,165,171);\n"
"	color: rgb(79,63,66);\n"
"}"));
        onlineButton->setCheckable(true);

        horizontalLayout_2->addWidget(onlineButton);


        retranslateUi(PlayerNumber);

        QMetaObject::connectSlotsByName(PlayerNumber);
    } // setupUi

    void retranslateUi(QDialog *PlayerNumber)
    {
        PlayerNumber->setWindowTitle(QApplication::translate("PlayerNumber", "Love Letter", Q_NULLPTR));
        label->setText(QApplication::translate("PlayerNumber", "SELECT THE NUMBER OF PLAYERS ", Q_NULLPTR));
        twoPlayersButton->setText(QApplication::translate("PlayerNumber", " 2 PLAYERS", Q_NULLPTR));
        threePlayersButton->setText(QApplication::translate("PlayerNumber", "3 PLAYERS", Q_NULLPTR));
        fourPlayersButton->setText(QApplication::translate("PlayerNumber", "4 PLAYERS", Q_NULLPTR));
        label_2->setText(QApplication::translate("PlayerNumber", "SELECT MODE", Q_NULLPTR));
        computerButton->setText(QApplication::translate("PlayerNumber", "COMPUTER ", Q_NULLPTR));
        onlineButton->setText(QApplication::translate("PlayerNumber", "ONLINE", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlayerNumber: public Ui_PlayerNumber {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERNUMBER_H

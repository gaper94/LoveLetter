/********************************************************************************
** Form generated from reading UI file 'information.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATION_H
#define UI_INFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Information
{
public:
    QWidget *verticalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;

    void setupUi(QDialog *Information)
    {
        if (Information->objectName().isEmpty())
            Information->setObjectName(QStringLiteral("Information"));
        Information->resize(700, 500);
        Information->setMinimumSize(QSize(700, 500));
        Information->setMaximumSize(QSize(700, 500));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ressources/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        Information->setWindowIcon(icon);
        Information->setStyleSheet(QLatin1String("background-image: url(:/ressources/bgrd.jpg); \n"
"background-position: center; \n"
"background-repeat: repeat-xy;"));
        verticalLayoutWidget = new QWidget(Information);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 681, 61));
        horizontalLayout = new QHBoxLayout(verticalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(150, 50));
        label->setMaximumSize(QSize(150, 50));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(25);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QLatin1String("color: white;\n"
"background:transparent;"));
        label->setFrameShadow(QFrame::Plain);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(Information);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(16, 90, 675, 400));
        label_2->setMinimumSize(QSize(675, 400));
        label_2->setMaximumSize(QSize(675, 400));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral("color:rgb(238, 238, 236)"));
        label_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_2->setWordWrap(true);

        retranslateUi(Information);

        QMetaObject::connectSlotsByName(Information);
    } // setupUi

    void retranslateUi(QDialog *Information)
    {
        Information->setWindowTitle(QApplication::translate("Information", "Rules", 0));
        label->setText(QApplication::translate("Information", "RULES", 0));
        label_2->setText(QApplication::translate("Information", "Love Letter is played in a series of rounds. Each round represents one day. At the end of each round, one player\342\200\231s letter reaches the Princess, and she reads it. When she reads enough letters from one suitor, she becomes enamored and grants that suitor permission to court her. That player wins the princess\342\200\231s heart and the game.\n"
"\n"
"TAKING A TURN\n"
"On your turn, draw the top card from the deck and add it to your hand. Then choose one of the two cards in your hand and discard it face up in front of you. Apply any effect on the card you discarded. You must apply its effect, even if it is bad for you. All discarded cards remain in front of the player who discarded them. Once you finish applying the card\342\200\231s effect, the turn passes to the player on your left.\n"
"\n"
"OUT OF THE ROUND\n"
"If a player is knocked out of the round, that player discards the card in his or her hand face up (do not apply the card\342\200\231s effect) and takes no more turns until next round.\n"
"\n"
""
                        "END OF A ROUND\n"
"A round ends if the deck is empty at the end of a turn. All players still in the round reveal their hands. The player with the highest ranked person wins the round. In case of a tie, the player who discarded the highest total value of cards wins.A round also ends if all players but one are out of the round, in which case the remaining player wins. ", 0));
    } // retranslateUi

};

namespace Ui {
    class Information: public Ui_Information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATION_H

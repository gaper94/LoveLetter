/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QLabel *userLabel;
    QLabel *scoreLabel;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *userLabel_2;
    QLabel *userLabel_3;
    QLabel *userLabel_4;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QTextEdit *textEdit;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;

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
        userLabel->setGeometry(QRect(600, 590, 150, 50));
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
        scoreLabel->setGeometry(QRect(0, 590, 341, 50));
        scoreLabel->setMinimumSize(QSize(0, 50));
        scoreLabel->setMaximumSize(QSize(350, 50));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        scoreLabel->setFont(font1);
        scoreLabel->setStyleSheet(QStringLiteral("background-color: rgb(32, 74, 135);"));
        scoreLabel->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(Game);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(440, 540, 155, 217));
        pushButton->setMinimumSize(QSize(155, 217));
        pushButton->setMaximumSize(QSize(155, 217));
        pushButton->setIconSize(QSize(155, 217));
        pushButton->setCheckable(true);
        pushButton->setChecked(false);
        pushButton->setFlat(false);
        pushButton_2 = new QPushButton(Game);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(true);
        pushButton_2->setGeometry(QRect(410, -130, 155, 217));
        pushButton_2->setMinimumSize(QSize(155, 217));
        pushButton_2->setMaximumSize(QSize(155, 217));
        pushButton_2->setIconSize(QSize(155, 217));
        pushButton_2->setCheckable(true);
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(Game);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(true);
        pushButton_3->setGeometry(QRect(-110, 220, 217, 155));
        pushButton_3->setMinimumSize(QSize(217, 155));
        pushButton_3->setMaximumSize(QSize(217, 155));
        pushButton_3->setIconSize(QSize(155, 217));
        pushButton_3->setCheckable(true);
        pushButton_3->setFlat(true);
        pushButton_4 = new QPushButton(Game);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setEnabled(true);
        pushButton_4->setGeometry(QRect(860, 210, 217, 155));
        pushButton_4->setMinimumSize(QSize(217, 155));
        pushButton_4->setMaximumSize(QSize(217, 155));
        pushButton_4->setIconSize(QSize(155, 217));
        pushButton_4->setCheckable(true);
        pushButton_4->setFlat(true);
        userLabel_2 = new QLabel(Game);
        userLabel_2->setObjectName(QStringLiteral("userLabel_2"));
        userLabel_2->setGeometry(QRect(0, 390, 150, 50));
        userLabel_2->setMinimumSize(QSize(150, 50));
        userLabel_2->setMaximumSize(QSize(150, 50));
        userLabel_2->setFont(font);
        userLabel_2->setStyleSheet(QStringLiteral("background-color: rgb(32, 74, 135);"));
        userLabel_2->setAlignment(Qt::AlignCenter);
        userLabel_3 = new QLabel(Game);
        userLabel_3->setObjectName(QStringLiteral("userLabel_3"));
        userLabel_3->setGeometry(QRect(810, 380, 150, 50));
        userLabel_3->setMinimumSize(QSize(150, 50));
        userLabel_3->setMaximumSize(QSize(150, 50));
        userLabel_3->setFont(font);
        userLabel_3->setStyleSheet(QStringLiteral("background-color: rgb(32, 74, 135);"));
        userLabel_3->setAlignment(Qt::AlignCenter);
        userLabel_4 = new QLabel(Game);
        userLabel_4->setObjectName(QStringLiteral("userLabel_4"));
        userLabel_4->setGeometry(QRect(250, 0, 150, 50));
        userLabel_4->setMinimumSize(QSize(150, 50));
        userLabel_4->setMaximumSize(QSize(150, 50));
        userLabel_4->setFont(font);
        userLabel_4->setStyleSheet(QStringLiteral("background-color: rgb(32, 74, 135);"));
        userLabel_4->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(Game);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEnabled(true);
        comboBox->setGeometry(QRect(340, 330, 271, 31));
        comboBox_2 = new QComboBox(Game);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(310, 370, 331, 31));
        pushButton_5 = new QPushButton(Game);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setEnabled(true);
        pushButton_5->setGeometry(QRect(770, 500, 100, 141));
        pushButton_5->setMaximumSize(QSize(100, 150));
        pushButton_5->setIconSize(QSize(100, 150));
        pushButton_5->setFlat(true);
        pushButton_6 = new QPushButton(Game);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setEnabled(true);
        pushButton_6->setGeometry(QRect(820, 500, 100, 141));
        pushButton_6->setMaximumSize(QSize(100, 150));
        pushButton_6->setIconSize(QSize(100, 150));
        pushButton_6->setFlat(true);
        pushButton_7 = new QPushButton(Game);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setEnabled(true);
        pushButton_7->setGeometry(QRect(870, 500, 100, 141));
        pushButton_7->setMaximumSize(QSize(100, 150));
        pushButton_7->setIconSize(QSize(100, 150));
        pushButton_7->setFlat(true);
        pushButton_8 = new QPushButton(Game);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(250, 420, 451, 71));
        pushButton_8->setStyleSheet(QStringLiteral("font: 20pt \"Ubuntu\";"));
        pushButton_8->setFlat(false);
        pushButton_9 = new QPushButton(Game);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(350, 540, 155, 217));
        pushButton_9->setMinimumSize(QSize(155, 217));
        pushButton_9->setMaximumSize(QSize(155, 217));
        pushButton_9->setIconSize(QSize(155, 217));
        pushButton_9->setCheckable(true);
        pushButton_9->setChecked(false);
        pushButton_9->setFlat(false);
        pushButton_10 = new QPushButton(Game);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(820, 20, 111, 151));
        pushButton_10->setMinimumSize(QSize(0, 0));
        pushButton_10->setMaximumSize(QSize(155, 217));
        pushButton_10->setIconSize(QSize(155, 217));
        pushButton_10->setCheckable(true);
        pushButton_10->setChecked(false);
        pushButton_10->setFlat(false);
        pushButton_11 = new QPushButton(Game);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(360, 450, 61, 81));
        pushButton_11->setMinimumSize(QSize(0, 0));
        pushButton_11->setMaximumSize(QSize(155, 217));
        pushButton_11->setIconSize(QSize(61, 81));
        pushButton_11->setCheckable(true);
        pushButton_11->setChecked(false);
        pushButton_11->setFlat(true);
        pushButton_12 = new QPushButton(Game);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(400, 450, 61, 81));
        pushButton_12->setMinimumSize(QSize(0, 0));
        pushButton_12->setMaximumSize(QSize(155, 217));
        pushButton_12->setIconSize(QSize(61, 81));
        pushButton_12->setCheckable(true);
        pushButton_12->setChecked(false);
        pushButton_12->setFlat(true);
        pushButton_13 = new QPushButton(Game);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(440, 450, 61, 81));
        pushButton_13->setMinimumSize(QSize(0, 0));
        pushButton_13->setMaximumSize(QSize(155, 217));
        pushButton_13->setIconSize(QSize(61, 81));
        pushButton_13->setCheckable(true);
        pushButton_13->setChecked(false);
        pushButton_13->setFlat(true);
        pushButton_14 = new QPushButton(Game);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(480, 450, 61, 81));
        pushButton_14->setMinimumSize(QSize(0, 0));
        pushButton_14->setMaximumSize(QSize(155, 217));
        pushButton_14->setIconSize(QSize(61, 81));
        pushButton_14->setCheckable(true);
        pushButton_14->setChecked(false);
        pushButton_14->setFlat(true);
        pushButton_15 = new QPushButton(Game);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(520, 450, 61, 81));
        pushButton_15->setMinimumSize(QSize(0, 0));
        pushButton_15->setMaximumSize(QSize(155, 217));
        pushButton_15->setIconSize(QSize(61, 81));
        pushButton_15->setCheckable(true);
        pushButton_15->setChecked(false);
        pushButton_15->setFlat(true);
        pushButton_16 = new QPushButton(Game);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(540, 100, 61, 81));
        pushButton_16->setMinimumSize(QSize(0, 0));
        pushButton_16->setMaximumSize(QSize(155, 217));
        pushButton_16->setIconSize(QSize(61, 81));
        pushButton_16->setCheckable(true);
        pushButton_16->setChecked(false);
        pushButton_16->setFlat(true);
        pushButton_17 = new QPushButton(Game);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(460, 100, 61, 81));
        pushButton_17->setMinimumSize(QSize(0, 0));
        pushButton_17->setMaximumSize(QSize(155, 217));
        pushButton_17->setIconSize(QSize(61, 81));
        pushButton_17->setCheckable(true);
        pushButton_17->setChecked(false);
        pushButton_17->setFlat(true);
        pushButton_18 = new QPushButton(Game);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(420, 100, 61, 81));
        pushButton_18->setMinimumSize(QSize(0, 0));
        pushButton_18->setMaximumSize(QSize(155, 217));
        pushButton_18->setIconSize(QSize(61, 81));
        pushButton_18->setCheckable(true);
        pushButton_18->setChecked(false);
        pushButton_18->setFlat(true);
        pushButton_19 = new QPushButton(Game);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(500, 100, 61, 81));
        pushButton_19->setMinimumSize(QSize(0, 0));
        pushButton_19->setMaximumSize(QSize(155, 217));
        pushButton_19->setIconSize(QSize(61, 81));
        pushButton_19->setCheckable(true);
        pushButton_19->setChecked(false);
        pushButton_19->setFlat(true);
        pushButton_20 = new QPushButton(Game);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(380, 100, 61, 81));
        pushButton_20->setMinimumSize(QSize(0, 0));
        pushButton_20->setMaximumSize(QSize(155, 217));
        pushButton_20->setIconSize(QSize(61, 81));
        pushButton_20->setCheckable(true);
        pushButton_20->setChecked(false);
        pushButton_20->setFlat(true);
        textEdit = new QTextEdit(Game);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(770, 600, 191, 41));
        textEdit->setTextInteractionFlags(Qt::NoTextInteraction);
        pushButton_21 = new QPushButton(Game);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(130, 200, 81, 61));
        pushButton_21->setMinimumSize(QSize(0, 0));
        pushButton_21->setMaximumSize(QSize(155, 217));
        pushButton_21->setIconSize(QSize(61, 81));
        pushButton_21->setCheckable(true);
        pushButton_21->setChecked(false);
        pushButton_21->setFlat(true);
        pushButton_22 = new QPushButton(Game);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(130, 230, 81, 61));
        pushButton_22->setMinimumSize(QSize(0, 0));
        pushButton_22->setMaximumSize(QSize(155, 217));
        pushButton_22->setIconSize(QSize(61, 81));
        pushButton_22->setCheckable(true);
        pushButton_22->setChecked(false);
        pushButton_22->setFlat(true);
        pushButton_23 = new QPushButton(Game);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setGeometry(QRect(130, 260, 81, 61));
        pushButton_23->setMinimumSize(QSize(0, 0));
        pushButton_23->setMaximumSize(QSize(155, 217));
        pushButton_23->setIconSize(QSize(61, 81));
        pushButton_23->setCheckable(true);
        pushButton_23->setChecked(false);
        pushButton_23->setFlat(true);
        pushButton_24 = new QPushButton(Game);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        pushButton_24->setGeometry(QRect(130, 290, 81, 61));
        pushButton_24->setMinimumSize(QSize(0, 0));
        pushButton_24->setMaximumSize(QSize(155, 217));
        pushButton_24->setIconSize(QSize(61, 81));
        pushButton_24->setCheckable(true);
        pushButton_24->setChecked(false);
        pushButton_24->setFlat(true);
        pushButton_25 = new QPushButton(Game);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        pushButton_25->setGeometry(QRect(130, 320, 81, 61));
        pushButton_25->setMinimumSize(QSize(0, 0));
        pushButton_25->setMaximumSize(QSize(155, 217));
        pushButton_25->setIconSize(QSize(61, 81));
        pushButton_25->setCheckable(true);
        pushButton_25->setChecked(false);
        pushButton_25->setFlat(true);
        pushButton_26 = new QPushButton(Game);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        pushButton_26->setGeometry(QRect(750, 220, 81, 61));
        pushButton_26->setMinimumSize(QSize(0, 0));
        pushButton_26->setMaximumSize(QSize(155, 217));
        pushButton_26->setIconSize(QSize(61, 81));
        pushButton_26->setCheckable(true);
        pushButton_26->setChecked(false);
        pushButton_26->setFlat(true);
        pushButton_27 = new QPushButton(Game);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        pushButton_27->setGeometry(QRect(750, 310, 81, 61));
        pushButton_27->setMinimumSize(QSize(0, 0));
        pushButton_27->setMaximumSize(QSize(155, 217));
        pushButton_27->setIconSize(QSize(61, 81));
        pushButton_27->setCheckable(true);
        pushButton_27->setChecked(false);
        pushButton_27->setFlat(true);
        pushButton_28 = new QPushButton(Game);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        pushButton_28->setGeometry(QRect(750, 250, 81, 61));
        pushButton_28->setMinimumSize(QSize(0, 0));
        pushButton_28->setMaximumSize(QSize(155, 217));
        pushButton_28->setIconSize(QSize(61, 81));
        pushButton_28->setCheckable(true);
        pushButton_28->setChecked(false);
        pushButton_28->setFlat(true);
        pushButton_29 = new QPushButton(Game);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));
        pushButton_29->setGeometry(QRect(750, 280, 81, 61));
        pushButton_29->setMinimumSize(QSize(0, 0));
        pushButton_29->setMaximumSize(QSize(155, 217));
        pushButton_29->setIconSize(QSize(61, 81));
        pushButton_29->setCheckable(true);
        pushButton_29->setChecked(false);
        pushButton_29->setFlat(true);
        pushButton_30 = new QPushButton(Game);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));
        pushButton_30->setGeometry(QRect(750, 190, 81, 61));
        pushButton_30->setMinimumSize(QSize(0, 0));
        pushButton_30->setMaximumSize(QSize(155, 217));
        pushButton_30->setIconSize(QSize(61, 81));
        pushButton_30->setCheckable(true);
        pushButton_30->setChecked(false);
        pushButton_30->setFlat(true);
        pushButton_16->raise();
        pushButton_19->raise();
        pushButton_17->raise();
        pushButton_18->raise();
        pushButton_20->raise();
        pushButton_11->raise();
        pushButton_12->raise();
        pushButton_13->raise();
        pushButton_14->raise();
        pushButton_15->raise();
        userLabel->raise();
        scoreLabel->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        userLabel_2->raise();
        userLabel_3->raise();
        userLabel_4->raise();
        comboBox->raise();
        comboBox_2->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        pushButton_10->raise();
        pushButton_8->raise();
        pushButton_9->raise();
        pushButton->raise();
        textEdit->raise();
        pushButton_21->raise();
        pushButton_22->raise();
        pushButton_23->raise();
        pushButton_24->raise();
        pushButton_25->raise();
        pushButton_26->raise();
        pushButton_27->raise();
        pushButton_28->raise();
        pushButton_29->raise();
        pushButton_30->raise();

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QDialog *Game)
    {
        Game->setWindowTitle(QApplication::translate("Game", "Love Letter", 0));
        userLabel->setText(QApplication::translate("Game", "TextLabel", 0));
        scoreLabel->setText(QApplication::translate("Game", "TextLabel", 0));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        userLabel_2->setText(QApplication::translate("Game", "TextLabel", 0));
        userLabel_3->setText(QApplication::translate("Game", "TextLabel", 0));
        userLabel_4->setText(QApplication::translate("Game", "TextLabel", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Game", "Choisir un joueur et presser entrer", 0)
         << QApplication::translate("Game", "Amadouceur", 0)
         << QApplication::translate("Game", "Petit_g", 0)
         << QApplication::translate("Game", "Anne", 0)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Game", "Choisir une carte \303\240 deviner et presser entrer", 0)
         << QApplication::translate("Game", "Pr\303\252tre", 0)
         << QApplication::translate("Game", "Baron", 0)
         << QApplication::translate("Game", "Servante", 0)
         << QApplication::translate("Game", "Prince", 0)
         << QApplication::translate("Game", "Roi", 0)
         << QApplication::translate("Game", "Comtesse", 0)
         << QApplication::translate("Game", "Princesse", 0)
        );
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QApplication::translate("Game", "PushButton", 0));
        pushButton_9->setText(QString());
        pushButton_10->setText(QString());
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        pushButton_15->setText(QString());
        pushButton_16->setText(QString());
        pushButton_17->setText(QString());
        pushButton_18->setText(QString());
        pushButton_19->setText(QString());
        pushButton_20->setText(QString());
        textEdit->setHtml(QApplication::translate("Game", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:16pt;\">Cartes retir\303\251es</span></p></body></html>", 0));
        pushButton_21->setText(QString());
        pushButton_22->setText(QString());
        pushButton_23->setText(QString());
        pushButton_24->setText(QString());
        pushButton_25->setText(QString());
        pushButton_26->setText(QString());
        pushButton_27->setText(QString());
        pushButton_28->setText(QString());
        pushButton_29->setText(QString());
        pushButton_30->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H

/********************************************************************************
** Form generated from reading UI file 'computer.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPUTER_H
#define UI_COMPUTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Computer
{
public:
    QLabel *label_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *easyButton;
    QPushButton *mediumButton;
    QPushButton *hardButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *startButton;
    QLabel *label;

    void setupUi(QDialog *Computer)
    {
        if (Computer->objectName().isEmpty())
            Computer->setObjectName(QStringLiteral("Computer"));
        Computer->resize(960, 640);
        Computer->setMinimumSize(QSize(960, 640));
        Computer->setMaximumSize(QSize(960, 640));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ressources/game_icon.png"), QSize(), QIcon::Normal, QIcon::On);
        Computer->setWindowIcon(icon);
        Computer->setStyleSheet(QLatin1String("/*\n"
"background-color: rgb(81, 60, 117);\n"
"*/"));
        label_2 = new QLabel(Computer);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 290, 960, 75));
        label_2->setMinimumSize(QSize(960, 75));
        label_2->setMaximumSize(QSize(960, 75));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QLatin1String("color: white;\n"
""));
        label_2->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(Computer);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(53, 140, 841, 102));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        easyButton = new QPushButton(horizontalLayoutWidget);
        easyButton->setObjectName(QStringLiteral("easyButton"));
        easyButton->setMinimumSize(QSize(250, 100));
        easyButton->setMaximumSize(QSize(250, 100));
        QFont font1;
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setWeight(75);
        easyButton->setFont(font1);
        easyButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255,229,232);\n"
"	color: rgb(227,91,120);\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"	background-color: rgb(227,91,120);\n"
"	color: rgb(255,229,232);\n"
"}"));
        easyButton->setCheckable(true);

        horizontalLayout->addWidget(easyButton, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        mediumButton = new QPushButton(horizontalLayoutWidget);
        mediumButton->setObjectName(QStringLiteral("mediumButton"));
        mediumButton->setMinimumSize(QSize(250, 100));
        mediumButton->setMaximumSize(QSize(250, 100));
        mediumButton->setFont(font1);
        mediumButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255,229,232);\n"
"	color: rgb(227,91,120);\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"	background-color: rgb(227,91,120);\n"
"	color: rgb(255,229,232);\n"
"}"));
        mediumButton->setCheckable(true);

        horizontalLayout->addWidget(mediumButton, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        hardButton = new QPushButton(horizontalLayoutWidget);
        hardButton->setObjectName(QStringLiteral("hardButton"));
        hardButton->setMinimumSize(QSize(250, 100));
        hardButton->setMaximumSize(QSize(250, 100));
        hardButton->setFont(font1);
        hardButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255,229,232);\n"
"	color: rgb(227,91,120);\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"	background-color: rgb(227,91,120);\n"
"	color: rgb(255,229,232);\n"
"}"));
        hardButton->setCheckable(true);

        horizontalLayout->addWidget(hardButton, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        horizontalLayoutWidget_2 = new QWidget(Computer);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(100, 410, 791, 121));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(100, 50));
        label_3->setMaximumSize(QSize(100, 50));
        QFont font2;
        font2.setPointSize(25);
        font2.setBold(true);
        font2.setUnderline(false);
        font2.setWeight(75);
        font2.setStrikeOut(false);
        label_3->setFont(font2);
        label_3->setStyleSheet(QLatin1String("color: white;\n"
"\n"
""));

        horizontalLayout_2->addWidget(label_3);

        lineEdit = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(350, 50));
        lineEdit->setMaximumSize(QSize(350, 50));
        QFont font3;
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        lineEdit->setFont(font3);
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lineEdit);

        startButton = new QPushButton(horizontalLayoutWidget_2);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setMinimumSize(QSize(200, 50));
        startButton->setMaximumSize(QSize(100, 50));
        startButton->setFont(font3);
        startButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255,229,232);\n"
"	color: rgb(227,91,120);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	background-color: rgb(194,165,171);\n"
"	color: rgb(79,63,66);\n"
"}"));
        startButton->setCheckable(true);

        horizontalLayout_2->addWidget(startButton);

        label = new QLabel(Computer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 960, 75));
        label->setMinimumSize(QSize(960, 75));
        label->setMaximumSize(QSize(960, 75));
        label->setFont(font);
        label->setStyleSheet(QLatin1String("color: white;\n"
""));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Computer);

        QMetaObject::connectSlotsByName(Computer);
    } // setupUi

    void retranslateUi(QDialog *Computer)
    {
        Computer->setWindowTitle(QApplication::translate("Computer", "Love Letter", 0));
        label_2->setText(QApplication::translate("Computer", "ENTER YOUR NAME", 0));
        easyButton->setText(QApplication::translate("Computer", "EASY", 0));
        mediumButton->setText(QApplication::translate("Computer", "MEDIUM", 0));
        hardButton->setText(QApplication::translate("Computer", "HARD", 0));
        label_3->setText(QApplication::translate("Computer", "NAME", 0));
        startButton->setText(QApplication::translate("Computer", "START", 0));
        label->setText(QApplication::translate("Computer", "SELECT MODE", 0));
    } // retranslateUi

};

namespace Ui {
    class Computer: public Ui_Computer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPUTER_H

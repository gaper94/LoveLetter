/********************************************************************************
** Form generated from reading UI file 'online.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINE_H
#define UI_ONLINE_H

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

class Ui_Online
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *startButton;
    QLabel *label;

    void setupUi(QDialog *Online)
    {
        if (Online->objectName().isEmpty())
            Online->setObjectName(QStringLiteral("Online"));
        Online->resize(960, 640);
        Online->setMinimumSize(QSize(960, 640));
        Online->setMaximumSize(QSize(960, 640));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ressources/game_icon.png"), QSize(), QIcon::Normal, QIcon::On);
        Online->setWindowIcon(icon);
        Online->setStyleSheet(QLatin1String("/*\n"
"background-color: rgb(81, 60, 117);\n"
"*/"));
        horizontalLayoutWidget = new QWidget(Online);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(173, 200, 671, 111));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(100, 50));
        label_2->setMaximumSize(QSize(100, 50));
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(350, 50));
        lineEdit->setMaximumSize(QSize(350, 50));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit->setFont(font1);

        horizontalLayout->addWidget(lineEdit);

        startButton = new QPushButton(horizontalLayoutWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setMinimumSize(QSize(200, 50));
        startButton->setMaximumSize(QSize(100, 50));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        startButton->setFont(font2);
        startButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255,229,232);\n"
"	color: rgb(227,91,120);\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	background-color: rgb(194,165,171);\n"
"	color: rgb(79,63,66);\n"
"}"));

        horizontalLayout->addWidget(startButton);

        label = new QLabel(Online);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 30, 960, 75));
        label->setMinimumSize(QSize(960, 75));
        label->setMaximumSize(QSize(960, 75));
        QFont font3;
        font3.setPointSize(28);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        label->setStyleSheet(QStringLiteral("color: white;"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Online);

        QMetaObject::connectSlotsByName(Online);
    } // setupUi

    void retranslateUi(QDialog *Online)
    {
        Online->setWindowTitle(QApplication::translate("Online", "Love Letter", Q_NULLPTR));
        label_2->setText(QApplication::translate("Online", "NAME", Q_NULLPTR));
        startButton->setText(QApplication::translate("Online", "START", Q_NULLPTR));
        label->setText(QApplication::translate("Online", "ENTER YOUR NAME", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Online: public Ui_Online {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINE_H

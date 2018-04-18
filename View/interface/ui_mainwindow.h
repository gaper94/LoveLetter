/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *playButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *infoButton;
    QPushButton *languageButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(960, 640);
        MainWindow->setMinimumSize(QSize(960, 640));
        MainWindow->setMaximumSize(QSize(960, 640));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ressources/game_icon.png"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral(""));
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(960, 640));
        centralWidget->setMaximumSize(QSize(960, 640));
        centralWidget->setStyleSheet(QLatin1String("text-align: center;\n"
""));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 90, 962, 551));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(960, 400, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        playButton = new QPushButton(verticalLayoutWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setMinimumSize(QSize(125, 75));
        playButton->setMaximumSize(QSize(125, 75));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        playButton->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ressources/button.png"), QSize(), QIcon::Normal, QIcon::Off);
        playButton->setIcon(icon1);
        playButton->setIconSize(QSize(125, 75));
        playButton->setCheckable(false);
        playButton->setAutoDefault(false);
        playButton->setFlat(true);

        horizontalLayout_2->addWidget(playButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(700, 150, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        infoButton = new QPushButton(centralWidget);
        infoButton->setObjectName(QStringLiteral("infoButton"));
        infoButton->setGeometry(QRect(860, 10, 75, 75));
        infoButton->setMinimumSize(QSize(75, 75));
        infoButton->setMaximumSize(QSize(75, 75));
        QFont font1;
        font1.setPointSize(40);
        font1.setBold(true);
        font1.setWeight(75);
        infoButton->setFont(font1);
        infoButton->setStyleSheet(QStringLiteral("background:transparent;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ressources/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        infoButton->setIcon(icon2);
        infoButton->setIconSize(QSize(75, 75));
        infoButton->setAutoDefault(false);
        infoButton->setFlat(true);
        languageButton = new QPushButton(centralWidget);
        languageButton->setObjectName(QStringLiteral("languageButton"));
        languageButton->setGeometry(QRect(770, 10, 75, 75));
        languageButton->setMinimumSize(QSize(75, 75));
        languageButton->setMaximumSize(QSize(75, 75));
        languageButton->setCheckable(true);
        languageButton->setAutoDefault(false);
        languageButton->setFlat(true);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        playButton->setDefault(false);
        infoButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Love Letter", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QApplication::translate("MainWindow", "Love Letter", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        playButton->setText(QString());
        infoButton->setText(QString());
        languageButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

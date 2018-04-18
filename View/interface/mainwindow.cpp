#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/ressources/page1.jpg"); //to use the images from Resources folder
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio); //background size
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QPushButton *languageButton = ui->languageButton;
    QPixmap english_icon(":/ressources/english.png");
    languageButton->setIcon(english_icon);
    languageButton->setIconSize(QSize(75, 75));
}

MainWindow::~MainWindow()
{
    delete ui;
    if(window != nullptr)
    {
        delete window;
    }

    if(rulesWindow != nullptr)
    {
        delete rulesWindow;
    }
}

void MainWindow::on_playButton_clicked()
{
    hide();
    if(window == nullptr)
    {
        window = new PlayerNumber(this);
    }
    window->show();
}


void MainWindow::on_infoButton_clicked()
{
    if(rulesWindow == nullptr)
    {
        rulesWindow = new Information(this);
    }
    rulesWindow->show();
}


void MainWindow::on_languageButton_toggled(bool checked)
{
    QPushButton *languageButton = ui->languageButton;
    if (checked == true)
    {
        QPixmap french_icon(":/ressources/francais.png");
        languageButton->setIcon(french_icon);
        languageButton->setIconSize(QSize(75, 75));
    }
    else
    {
        QPixmap english_icon(":/ressources/english.png");
        languageButton->setIcon(english_icon);
        languageButton->setIconSize(QSize(75, 75));
    }
}

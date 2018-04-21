#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

std::string language;

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
    language = "english";
    rulesWindow = new Information(this);
    window = new PlayerNumber(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnControllerConnect()
{
    if(window != nullptr)
    {
        window->OnControllerConnect();
    }
}

void MainWindow::OnControllerDisconnect()
{
    if(window != nullptr)
    {
        window->OnControllerDisconnect();
    }
}

void MainWindow::SetMsgSender(MsgSender msgSender)
{
    m_msgSender = msgSender;
    if(window != nullptr)
    {
        window->SetMsgSender(msgSender);
    }
}

void MainWindow::OnMsgReceived(const Msg &msg)
{
    if(window != nullptr)
    {
        window->OnMsgReceived(msg);
    }
}


void MainWindow::on_playButton_clicked()
{
    hide();
    window->show();
}


void MainWindow::on_infoButton_clicked()
{
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
        language = "french";
        //std::cout << language << std::endl; //pour tester que la variable se change
    }
    else
    {
        QPixmap english_icon(":/ressources/english.png");
        languageButton->setIcon(english_icon);
        languageButton->setIconSize(QSize(75, 75));
        language = "english";
        //std::cout << language << std::endl;
    }
}

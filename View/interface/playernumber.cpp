#include "playernumber.h"
#include "ui_playernumber.h"
#include "computer.h"
#include "online.h"

PlayerNumber::PlayerNumber(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerNumber),
    windowComputer(new Computer(this)),
    windowOnline(new Online(this))

{
    ui->setupUi(this);

    //background image
    QPixmap bkgnd(":/ressources/window_background.jpg"); //to use the images from Resources folder
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio); //background size
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    //add shadow to Qlabel
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(5);
    effect->setColor(QColor("bb8893"));
    effect->setOffset(2,2);
    ui->label->setGraphicsEffect(effect);

    QGraphicsDropShadowEffect *effect2 = new QGraphicsDropShadowEffect(this);
    effect2->setBlurRadius(5);
    effect2->setColor(QColor("bb8893"));
    effect2->setOffset(2,2);
    ui->label_2->setGraphicsEffect(effect2);

    ui->computerButton->setEnabled(false);
    ui->onlineButton->setEnabled(false);
}

PlayerNumber::~PlayerNumber()
{
    delete ui;
    delete windowComputer;
    delete windowOnline;
}

int nb_players;

void PlayerNumber::OnControllerConnect()
{
    m_controllerConnected = true;
    if(windowComputer != nullptr)
    {
        windowComputer->OnControllerConnect();
    }
}

void PlayerNumber::OnControllerDisconnect()
{
    m_controllerConnected = false;
    if(windowComputer != nullptr)
    {
        windowComputer->OnControllerConnect();
    }
}

void PlayerNumber::SetMsgSender(MsgSender msgSender)
{
    m_msgSender = msgSender;
    if(windowComputer != nullptr)
    {
        windowComputer->SetMsgSender(msgSender);
    }
}

//2 Players
void PlayerNumber::on_twoPlayersButton_toggled(bool checked)
{
    if (checked == true)
    {
        nb_players = 2;
        ui->threePlayersButton->setChecked(false);
        ui->fourPlayersButton->setChecked(false);

        ui->computerButton->setEnabled(true);
        ui->onlineButton->setEnabled(true);
    }
}

//3 Players
void PlayerNumber::on_threePlayersButton_toggled(bool checked)
{
    if (checked == true)
    {
        nb_players = 3;
        ui->twoPlayersButton->setChecked(false);
        ui->fourPlayersButton->setChecked(false);

        ui->computerButton->setEnabled(true);
        ui->onlineButton->setEnabled(true);
    }
}

//4 players
void PlayerNumber::on_fourPlayersButton_toggled(bool checked)
{
    if (checked == true)
    {
        nb_players = 4;
        ui->twoPlayersButton->setChecked(false);
        ui->threePlayersButton->setChecked(false);

        ui->computerButton->setEnabled(true);
        ui->onlineButton->setEnabled(true);
    }
}

void PlayerNumber::on_computerButton_clicked()
{
    if ((ui->twoPlayersButton->isChecked()==true) || (ui->threePlayersButton->isChecked()==true) ||
            (ui->fourPlayersButton->isCheckable()==true))
    {
        if(m_controllerConnected == true)
        {
            hide();
            windowComputer->show();
        }
    }
}

void PlayerNumber::on_onlineButton_clicked()
{
    if ((ui->twoPlayersButton->isChecked()==true) || (ui->threePlayersButton->isChecked()==true) ||
            (ui->fourPlayersButton->isCheckable()==true))
    {
        hide();
        windowOnline->show();
    }
}







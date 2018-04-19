#include "computer.h"
#include "ui_computer.h"

Computer::Computer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Computer)
{
    ui->setupUi(this);

    //background
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

    QGraphicsDropShadowEffect *effect3 = new QGraphicsDropShadowEffect(this);
    effect3->setBlurRadius(5);
    effect3->setColor(QColor("bb8893"));
    effect3->setOffset(2,2);
    ui->label_3->setGraphicsEffect(effect3);

    textArea = ui->lineEdit;

    textArea->setPlaceholderText("Enter your name. Ex: Lilu...");
    textArea->setMaxLength(15); //nicknames <= 8 caracters

    startButton = ui->startButton;
    startButton->setEnabled(false);

    windowGame = new Game(this);

    connect(textArea, SIGNAL(textChanged(QString)), this, SLOT(TextChanged(QString)));
    //connect(startButton, SIGNAL(clicked()), this, SLOT(on_startButton_clicked()));

}

Computer::~Computer()
{
    delete ui;
}

void Computer::OnControllerConnect()
{
    m_controllerConnected = true;
}

void Computer::OnControllerDisconnect()
{
    m_controllerConnected = false;
}

void Computer::SetMsgSender(MsgSender msgSender)
{
    m_msgSender = msgSender;
}

void Computer::on_easyButton_toggled(bool checked)
{
    if (checked == true)
    {
        game_mode = "easy";
        ui->mediumButton->setChecked(false);
        ui->hardButton->setChecked(false);
    }
}

void Computer::on_mediumButton_toggled(bool checked)
{
    if (checked == true)
    {
        game_mode = "medium";
        ui->easyButton->setChecked(false);
        ui->hardButton->setChecked(false);
    }
}

void Computer::on_hardButton_toggled(bool checked)
{
    if (checked == true)
    {
        game_mode = "hard";
        ui->easyButton->setChecked(false);
        ui->mediumButton->setChecked(false);
    }
}

QString name;

void Computer::on_startButton_clicked()
{
    name = textArea->text(); //save the username in name
    if ((ui->easyButton->isChecked()==true) || (ui->mediumButton->isChecked()==true)
            || (ui->hardButton->isChecked()==true))
    {
        if(m_controllerConnected == true)
        {
            hide();
            windowGame->Update();
            windowGame->show();
            _sendInitMsg();
        }
    }
    else
    {
        startButton->setEnabled(false);
    }
}

void Computer::TextChanged(QString str)
{
    name = str;
    startButton->setEnabled(!str.isEmpty());
}

void Computer::_sendMsg(const Msg& msg)
{
    if(m_msgSender != nullptr)
    {
        m_msgSender(msg);
    }
}

void Computer::_sendInitMsg()
{
    Msg msg;
    msg.name = "players_config";
    int32_t numberOfPlayers = nb_players;

    msg.AddValue("number_of_players", numberOfPlayers);
    std::string playerName = name.toStdString();
    msg.AddValue("player_name", playerName);
    std::string AIplayersMode = game_mode.toStdString();
    msg.AddValue("ai_players_mode", AIplayersMode);

    _sendMsg(msg);

    Msg startMsg;
    startMsg.name = "start_game";
    _sendMsg(startMsg);
}





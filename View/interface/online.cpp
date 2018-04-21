#include "online.h"
#include "ui_online.h"

Online::Online(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Online)
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

    textArea = ui->lineEdit;

    textArea->setPlaceholderText(tr("Enter your name. Ex: Lilu..."));
    textArea->setMaxLength(15); //nicknames <= 8 caracters

    startButton = ui->startButton;
    startButton->setEnabled(false);

    connect(textArea, SIGNAL(textChanged(QString)), this, SLOT(TextChanged(QString)));
}

Online::~Online()
{
    delete ui;
}

void Online::on_startButton_clicked()
{
    name = textArea->text();

    hide();
    windowGame = new Game(this);
    windowGame->show();
}

void Online::TextChanged(QString str)
{
    startButton->setEnabled(!str.isEmpty());
}


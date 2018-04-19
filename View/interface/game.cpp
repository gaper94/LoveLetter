#include "game.h"
#include "card.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);

    userLabel = ui->userLabel;

    Update();

    /*
    QPalette pal = userLabel->palette();
    pal.setBrush(QPalette::Background, Qt::black);
    userLabel->setAutoFillBackground(true); // IMPORTANT!
    userLabel->setPalette(pal);
    */

    /*
     * ESSAYAGE DE CARTES. PAS REGARDER
    //carte 1 a droite
    QPixmap carte(":/ressources/cards/resized/princess.png");
    ui->cardLabel->setPixmap(carte);

    //carte 2 a gauche
    QPixmap carte2(":/ressources/cards/resized/king.png");
    ui->cardLabel_2->setPixmap(carte2);

    //carte3 en haut droite
    QPixmap back_card(":/ressources/cards/resized/back_card.png");
    ui->cardLabel_3->setPixmap(back_card);

    ui->cardLabel_4->setPixmap(back_card);

    QLabel *card1 = new QLabel();
    card1->setGeometry(320, -130, 155, 217);
    setMyCard(card1, "back_card");
    */
}

Game::~Game()
{
    delete ui;
}

void Game::Update()
{
    //Score
    int score_player1 = 1;
    int score_player2 = 5;
    int score_player3 = 4;
    int score_player4 = 3;

    QString username = QString("%1").arg(name);
    userLabel->setText(username);

    if (nb_players == 2)
    {
        QString score = QString("SCORE:  %1: %2  Jack: %3").arg(name).arg(score_player1).arg(score_player2);
        ui->scoreLabel->setText(score);
    }
    else if (nb_players == 3)
    {
        QString score = QString("SCORE:  %1: %2  Jack: %3  Alice: %4").arg(name).arg(score_player1).arg(score_player2).arg(score_player3);
        ui->scoreLabel->setText(score);
    }
    else if (nb_players == 4)
    {
        QString score = QString("SCORE:  %1: %2  Jack: %3  Alice: %4  Tom: %5").arg(name).arg(score_player1).arg(score_player2).arg(score_player3).arg(score_player4);
        ui->scoreLabel->setText(score);
    }
}

//Function that sets the label n to a given card
void Game::setMyCard(QLabel *n,QString card_name)
{
    if (card_name == "Princess")
    {
        QPixmap my_card(":/ressources/cards/resized/princess.png");
        n->setPixmap(my_card);
    }
    else if (card_name == "Prince")
    {
        QPixmap my_card(":/ressources/cards/resized/prince.png");
        n->setPixmap(my_card);
    }
    else if (card_name == "Priest")
    {
        QPixmap my_card(":/ressources/cards/resized/priest.png");
        n->setPixmap(my_card);
    }
    else if (card_name == "King")
    {
        QPixmap my_card(":/ressources/cards/resized/king.png");
        n->setPixmap(my_card);
    }
    else if (card_name == "Handmaiden")
    {
        QPixmap my_card(":/ressources/cards/resized/handmaid.png");
        n->setPixmap(my_card);
    }
    else if (card_name == "Guard")
    {
        QPixmap my_card(":/ressources/cards/resized/guard.png");
        n->setPixmap(my_card);
    }
    else if (card_name == "Countess")
    {
        QPixmap my_card(":/ressources/cards/resized/countess.png");
        n->setPixmap(my_card);
    }
    else if (card_name == "Baron")
    {
        QPixmap my_card(":/ressources/cards/resized/baron.png");
        n->setPixmap(my_card);
    }
    else if (card_name == "back_card")
    {
        QPixmap my_card(":/ressources/cards/resized/back_card.png");
        n->setPixmap(my_card);
    }
}


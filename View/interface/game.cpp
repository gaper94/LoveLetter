#include "game.h"
#include "card.h"
#include "ui_game.h"
#include <iostream>


Game::~Game()
{
    delete ui;
}

std::string Game::NumberToString(int n)
{
    std::string card = "None";
    if (n == 1)
        card = "Guard";
    if (n==2)
        card = "Priest";
    if(n==3)
        card = "Baron";
    if(n==4)
        card = "Handmaiden";
    if (n==5)
        card = "Prince";
    if (n==6)
        card = "King";
    if (n==7)
        card = "Countess";
    if (n==8)
        card = "Princess";
    return card;
}

//Function that sets the label n to a given card
int Game::setMyCard(QPushButton *n,std::string card_name)
{
    if (card_name == "Princess")
    {
        QPixmap my_card(":/ressources/cards/resized/princess.png");
        n->setIcon(my_card);
        return 8;
    }
    else if (card_name == "Prince")
    {
        QPixmap my_card(":/ressources/cards/resized/prince.png");
        n->setIcon(my_card);
        return 5;
    }
    else if (card_name == "Priest")
    {
        QPixmap my_card(":/ressources/cards/resized/priest.png");
        n->setIcon(my_card);
        return 2;
    }
    else if (card_name == "King")
    {
        QPixmap my_card(":/ressources/cards/resized/king.png");
        n->setIcon(my_card);
        return 6;
    }
    else if (card_name == "Handmaiden")
    {
        QPixmap my_card(":/ressources/cards/resized/handmaid.png");
        n->setIcon(my_card);
        return 4;
    }
    else if (card_name == "Guard")
    {
        QPixmap my_card(":/ressources/cards/resized/guard.png");
        n->setIcon(my_card);
        return 1;
    }
    else if (card_name == "Countess")
    {
        QPixmap my_card(":/ressources/cards/resized/countess.png");
        n->setIcon(my_card);
        return 7;
    }
    else if (card_name == "Baron")
    {
        QPixmap my_card(":/ressources/cards/resized/baron.png");
        n->setIcon(my_card);
        return 2;
    }
    else if (card_name == "back_card")
    {
        QPixmap my_card(":/ressources/cards/resized/back_card.png");
        n->setIcon(my_card);
        return 0;
    }
    return 0;
  }


void Game::afficheCardsDiscard()
{

   // Msg msg =_onControllerMsgReceived(IConnection::ConnectionId, const IConnection::Msg& m);
   // int discard1 = setMyCard(ui->pushButton_5, ReceiveCardDiscard(msg));
   // Msg msg1 =_onControllerMsgReceived(IConnection::ConnectionId, const IConnection::Msg& m);
    //int discard2 = setMyCard(ui->pushButton_6, ReceiveCardDiscard(msg1));
   // Msg msg2 =_onControllerMsgReceived(IConnection::ConnectionId, const IConnection::Msg& m);
    //int discard3 = setMyCard(ui->pushButton_7, ReceiveCardDiscard(msg2));

//    QPixmap imgCard(":/ressources/cards/resized/princess.png");
//    ui->pushButton_5->setIcon(imgCard.scaled(100,150, Qt::IgnoreAspectRatio, Qt::FastTransformation)); //pour reduire la taille de la carte
//    ui->pushButton_5->resize(100,150); //pour reduire la taille du button
//    QPixmap imgCard2(":/ressources/cards/resized/princess.png");
//    ui->pushButton_6->setIcon(imgCard2.scaled(100,150, Qt::IgnoreAspectRatio, Qt::FastTransformation)); //pour reduire la taille de la carte
//    ui->pushButton_6->resize(100,150); //pour reduire la taille du button
//    QPixmap imgCard3(":/ressources/cards/resized/princess.png");
//    ui->pushButton_7->setIcon(imgCard3.scaled(100,150, Qt::IgnoreAspectRatio, Qt::FastTransformation)); //pour reduire la taille de la carte
//    ui->pushButton_7->resize(100,150); //pour reduire la taille du button
}

void Game::cacheCardsDiscards()
{
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->textEdit->hide();

}


Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    ui->comboBox->hide();
    ui->comboBox_2->hide();
    ui->pushButton_8->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->pushButton_14->hide();
    ui->pushButton_15->hide();


    userLabel = ui->userLabel;
    Update();
    
  //QString username =QString("BLABLA"); //Pour tester si marche
    QGraphicsScene scene(-683,-384, 1366,768);
    QString username = QString("%1").arg(name);
    userLabel->setText(username);

    // Msg msg = _onControllerMsgReceived(IConnection::ConnectionId, const IConnection::Msg& msg);
    // int my_res = setMyCard(ui->pushButton, ReceiveCard(msg)); //ma carte1//card1
    // msg = _onControllerMsgReceived(IConnection::ConnectionId, const IConnection::Msg& msg); //recieve
    // int my_res2 = setMyCard(ui->pushButton_9, ReceiveCard(msg));//ma carte2//card2

    //Carte du deck
    QPixmap imgCard(":/ressources/cards/resized/back_card.png");
    ui->pushButton_10->setIcon(imgCard.scaled(111,151, Qt::IgnoreAspectRatio, Qt::FastTransformation)); //pour reduire la taille de la carte
    ui->pushButton_10->resize(111,151); //pour reduire la taille du button

    //mes cartes déjà jouées
    int b = setMyCard(ui->pushButton_11, "Guard");
    int c = setMyCard(ui->pushButton_12, "Princess");
    int d = setMyCard(ui->pushButton_13, "Handmaiden");
    int e = setMyCard(ui->pushButton_14, "King");
    int f = setMyCard(ui->pushButton_15, "Baron");

    int other_res = setMyCard(ui->pushButton_2, "back_card");

    //set card 90°, left
    QMatrix rm;
    rm.rotate(90);
    QPixmap my_card(":/ressources/cards/resized/back_card.png");
    my_card = my_card.transformed(rm);
    ui->pushButton_3->setIcon(my_card);
    ui->pushButton_3->setIconSize(QSize(217,155));

    //set card 90° right
    QPixmap my_card2(":/ressources/cards/resized/back_card.png");
    my_card2 = my_card2.transformed(rm);
    ui->pushButton_4->setIcon(my_card2);
    ui->pushButton_4->setIconSize(QSize(217,155));


    int score_player1 = 1;
    int score_player2 = 5;
    int score_player3 = 4;
    int score_player4 = 3;

    ui->userLabel_4->setText("Jack");
    ui->userLabel_2->setText("Tom");
    ui->userLabel_3->setText("Alice");

    if (nb_players == 2)
    {

     afficheCardsDiscard();
     QString score = QString("SCORE:  %1: %2  Jack: %3").arg(name).arg(score_player1).arg(score_player2);
     ui->scoreLabel->setText(score);

     ui->pushButton_3->hide();
     ui->pushButton_4->hide();

     ui->userLabel_2->hide();
     ui->userLabel_3->hide();

     QString nb = QString("nbTours : %1 ").arg(nbTours);
     ui->userLabel_4->setText(nb);

     QMatrix rm180;
     rm180.rotate(180);
     QPixmap my_card1(":/ressources/cards/resized/guard.png");
     my_card1 = my_card1.transformed(rm180);
     ui->pushButton_16->setIcon(my_card1);
     QPixmap my_card2(":/ressources/cards/resized/princess.png");
     my_card2 = my_card2.transformed(rm180);
     ui->pushButton_17->setIcon(my_card2);
     QPixmap my_card3(":/ressources/cards/resized/baron.png");
     my_card3 = my_card3.transformed(rm180);
     ui->pushButton_18->setIcon(my_card3);
     QPixmap my_card4(":/ressources/cards/resized/king.png");
     my_card4 = my_card4.transformed(rm180);
     ui->pushButton_19->setIcon(my_card4);
     QPixmap my_card5(":/ressources/cards/resized/prince.png");
     my_card5 = my_card5.transformed(rm180);
     ui->pushButton_20->setIcon(my_card5);

     cardButton = ui->pushButton;
     connect(cardButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
     cardButton2 = ui->pushButton_9;
     connect(cardButton2, SIGNAL(clicked()), this, SLOT(on_pushButton_9_clicked()));


    }
    else if (nb_players == 3)
    {
        cacheCardsDiscards();
        QString score = QString("SCORE:  %1: %2  Tom: %3  Alice: %4").arg(name).arg(score_player1).arg(score_player2).arg(score_player3);
        ui->scoreLabel->setText(score);

        ui->pushButton_2->hide();
        ui->userLabel_4->hide(); 
         ui->pushButton_16->hide();
         ui->pushButton_17->hide();
         ui->pushButton_18->hide();
         ui->pushButton_19->hide();
         ui->pushButton_20->hide();
    }
    else if (nb_players == 4)
    {
        cacheCardsDiscards();
        QString score = QString("SCORE:  %1: %2  Tom: %3  Alice: %4  Jack: %5").arg(name).arg(score_player1).arg(score_player2).arg(score_player3).arg(score_player4);
        ui->scoreLabel->setText(score);



        QMatrix rm180;
        rm180.rotate(180);
        QPixmap my_card1(":/ressources/cards/resized/guard.png");
        my_card1 = my_card1.transformed(rm180);
        ui->pushButton_16->setIcon(my_card1);
        QPixmap my_card2(":/ressources/cards/resized/princess.png");
        my_card2 = my_card2.transformed(rm180);
        ui->pushButton_17->setIcon(my_card2);
        QPixmap my_card3(":/ressources/cards/resized/baron.png");
        my_card3 = my_card3.transformed(rm180);
        ui->pushButton_18->setIcon(my_card3);
        QPixmap my_card4(":/ressources/cards/resized/king.png");
        my_card4 = my_card4.transformed(rm180);
        ui->pushButton_19->setIcon(my_card4);
        QPixmap my_card5(":/ressources/cards/resized/prince.png");
        my_card5 = my_card5.transformed(rm180);
        ui->pushButton_20->setIcon(my_card5);
    }

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

void Game::on_pushButton_clicked()
{
    Msg msg;
    whatCard = 1;
    ui->pushButton->setGeometry(QRect(400, 190, 80, 150)); //changer la position du bouton. Les valeurs: 1,2 - la position dans la fenetre, 3-largeur du l'image, 4-longueur de l'image
    if (my_res == 1 || my_res == 2 || my_res == 3 || my_res == 6)
    {
        affiche_combo_J();
    }
     if (my_res == 1 && !(ui->comboBox->isVisible()))
        affiche_combo_C();
     if (my_res == 2 && !(ui->comboBox->isVisible()))
     {
          QPixmap card(":/ressources/cards/resized/baron.png");
          ui->pushButton_2->setIcon(card);
          QString priest_effect = QString("Ok !");
          ui->pushButton_8->setText(priest_effect);
          ui->pushButton_8->show();
          connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_pushButton_8_clicked()));


     }
     if (my_res == 8)
     {
         QString princess_effect = QString("Vous avez perdu !");
         ui->pushButton_8->setText(princess_effect);
         ui->pushButton_8->show();
         connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_pushButton_8_clicked()));
     }
     if (my_res == 4)
     {
         QString servante_effect = QString("Vous êtes protégé pour ce tour");
         ui->pushButton_8->setText(servante_effect);
         ui->pushButton_8->show();
         connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_pushButton_8_clicked()));
     }


}

void Game::on_pushButton_9_clicked()
{
    Msg msg;
    whatCard = 2;
    ui->pushButton_9->setGeometry(QRect(400, 190, 80, 150)); //changer la position du bouton. Les valeurs: 1,2 - la position dans la fenetre, 3-largeur du l'image, 4-longueur de l'image
    if (my_res2 == 1 || my_res2 == 2 || my_res2 == 3 || my_res2 == 6)
    {
        affiche_combo_J();
    }
     if (my_res2 == 1 && !(ui->comboBox->isVisible()))
        affiche_combo_C();
     if (my_res2 == 2 && !(ui->comboBox->isVisible()))
     {
          QPixmap card(":/ressources/cards/resized/baron.png");
          ui->pushButton_2->setIcon(card);
          QString priest_effect = QString("Ok !");
          ui->pushButton_8->setText(priest_effect);
          ui->pushButton_8->show();
          connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_pushButton_8_clicked()));


     }
     if (my_res2 == 8)
     {
         QString princess_effect = QString("Vous avez perdu !");
         ui->pushButton_8->setText(princess_effect);
         ui->pushButton_8->show();
         connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_pushButton_8_clicked()));
     }
     if (my_res2 == 4)
     {
         QString servante_effect = QString("Vous êtes protégé pour ce tour");
         ui->pushButton_8->setText(servante_effect);
         ui->pushButton_8->show();
         connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_pushButton_8_clicked()));
     }

}

void Game::on_pushButton_10_clicked()
{
    if(ui->pushButton_8->isHidden())
    {
        if (whatCard == 1)
        {
            ui->pushButton_9->setGeometry(QRect(350, 540, 80, 150));
            ui->pushButton->setGeometry(QRect(440, 540, 80, 150));
            ui->pushButton->show();
        }
        if (whatCard == 2)
        {
            ui->pushButton->setGeometry(QRect(350, 540, 80, 150));
            ui->pushButton_9->setGeometry(QRect(440, 540, 80, 150));
            ui->pushButton_9->show();
        }
    }
}


void Game::affiche_combo_J()
{
    combo_J = ui->comboBox;
    ui->comboBox->show();
    int number = ui->comboBox->currentIndex();
    if (number != 0)
    {
        choisirJoueur = ui->comboBox->currentText();
        ui->userLabel_4->setText(choisirJoueur);
        ui->comboBox->hide();
    }
}

void Game::affiche_combo_C()
{
    combo_C = ui->comboBox_2;
    ui->comboBox_2->show();
    int n = ui->comboBox_2->currentIndex();
    if (n != 0)
    {
        QString bla = ui->comboBox_2->currentText();
        ui->userLabel_4->setText(bla);
        ui->comboBox_2->hide();
    }
}


void Game::on_pushButton_8_clicked()
{
    ui->pushButton_8->hide();
    if (whatCard == 1)
    {
        if (my_res == 2)
            int other_res2 = setMyCard(ui->pushButton_2, "back_card");
        ui->pushButton->setGeometry(QRect(420, 540, 80, 150));
        ui->pushButton->hide();
        ui->pushButton_9->setGeometry(QRect(420, 540, 80, 150));
        QIcon i = ui->pushButton->icon();
        if (nbTours == 1)
        {
            ui->pushButton_13->setIcon(i);
            ui->pushButton_13->show();
        }
        if (nbTours == 3)
        {
            ui->pushButton_12->setIcon(i);
            ui->pushButton_12->show();
        }
        if (nbTours == 5)
        {
            ui->pushButton_14->setIcon(i);
            ui->pushButton_14->show();
        }
        if (nbTours == 7)
        {
            ui->pushButton_11->setIcon(i);
            ui->pushButton_11->show();
        }
        if (nbTours == 9)
        {
            ui->pushButton_15->setIcon(i);
            ui->pushButton_15->show();
        }
    }
    if (whatCard == 2)
    {
        if (my_res2 == 2)
            int other_res2 = setMyCard(ui->pushButton_2, "back_card");
        ui->pushButton_9->setGeometry(QRect(420, 540, 80, 150));
        ui->pushButton_9->hide();
        ui->pushButton->setGeometry(QRect(420, 540, 80, 150));
        QIcon i = ui->pushButton_9->icon();
        if (nbTours == 1)
        {
            ui->pushButton_13->setIcon(i);
            ui->pushButton_13->show();
        }
        if (nbTours == 3)
        {
            ui->pushButton_12->setIcon(i);
            ui->pushButton_12->show();
        }
        if (nbTours == 5)
        {
            ui->pushButton_14->setIcon(i);
            ui->pushButton_14->show();
        }
        if (nbTours == 7)
        {
            ui->pushButton_11->setIcon(i);
            ui->pushButton_11->show();
        }
        if (nbTours == 9)
        {
            ui->pushButton_15->setIcon(i);
            ui->pushButton_15->show();
        }

    }
}

void Game::SetMsgSender(MsgSender msgSender)
{
    m_msgSender = msgSender;
}

void Game::SendMsg(const Msg& msg)
{
    if(m_msgSender != nullptr)
    {
        m_msgSender(msg);
    }
}

void Game::OnMsgReceived(const Msg& msg)
{
    if(msg.name == "discarted_cards")
    {
        std::vector<Card> cards;
        msg.GetValue("dcards",cards);
    }

    if(msg.name == "picked_cards")
    {
        Card c;
        msg.GetValue("cards",c);
    }
}

#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QLabel>
#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QRectF>
#include <QComboBox>
#include <QGraphicsScene>
#include "utils.h"
#include "../../Network/IConnection.h"
#include "../../GameCommon/Card.h"
#include "../../Msg/Deserializer.h"
#include <vector>
#include <iostream>

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();
    std::string NumberToString(int n);
    void Update();
    void SendMsg(const Msg& msg);
    void SetMsgSender(MsgSender msgSender);
    void OnMsgReceived(const Msg& msg);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void affiche_combo_J();
    void affiche_combo_C();
    void afficheCardsDiscard();
    void cacheCardsDiscards();
    //void on_pushButton_2_clicked();
    // void SendCardPlayed (const Msg& msg, std::string card);
    // void SendGuessCard (const Msg& msg, std::string card);
    // void SendFightPlayer (const Msg& msg, std::string joueur);
    // std::string ReceiveCardDiscard (const Msg& msg);
    // std::string ReceiveCardPick (const Msg& msg);


    void on_pushButton_8_clicked();

private:
    QLabel *userLabel;
    Ui::Game *ui;
    QPushButton *cardButton;
    QPushButton *cardButton2;
    QComboBox * combo_J;
    QComboBox * combo_C;
    QString choisirJoueur;
    int my_res;
    int my_res2;
    int whatCard;
    int nbTours = 1;
    MsgSender m_msgSender = nullptr;
    void _sendMsg(const Msg&);
    int setMyCard(QPushButton *n,std::string card_name);

};

#endif // GAME_H

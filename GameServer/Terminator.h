#ifndef _TERMINATOR__H
#define _TERMINATOR__H

#define PLAYER_NUMBER 2
#define CARD_NUMBER 8
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <map>
#include "InfSup_Bot.h"
#include "Joueur.h"
#include "../GameCommon/GameUtils.h"


class Terminator: public InfSup_Bot
{
public:
	Terminator(const std::string& name); //constructeur
	

	Card ChoisirCarte();	//For all
	std::string ChoisirJoueur(PlayersContainer& vectorPlayer, int nbPlayers);	//Guard, Priest, Baron, Prince, King
	Card DevinerCarte();	//Guard

	Card PlayLowest();
	Card PlayNotPrincess();
	int CardsLeftPlayed(CardType t);

	int GetIndiceJoueurLastPlayedCardHighest();
	int GetIndiceJoueurLastPlayedCardLowest();
	bool GoodPlayBaron();

	Card PlayPriest();
	Card PlayGuard();
	Card PlayBaron();
	Card PlayHandmaiden();
	Card PlayPrince();
	Card PlayKing();
	Card PlayCountess();
	Card PlayUnknown();

	Card Think();
	Card ThinkGuard();
	Card ThinkPriest();
	Card ThinkBaron();
	Card ThinkHandmaiden();
	Card ThinkPrince();
	Card ThinkKing();
	Card ThinkCountess();
	Card ThinkUnknown();

	bool inHand(CardType t);
	bool inHandTwice(CardType t);

	void PrintPlayedCard();

    virtual bool IsAIPlayer() { return true; }

protected:

	bool toGuard = false;
	bool toPriest = false;
	bool toBaron = false;
	bool toPrince = false;
	bool toKing = false;
	bool firstRound = false;

	std::string playerToGuard = "playerTo";
	std::string playerToPriest = "playerTo";
	std::string playerToBaron = "playerTo";
	std::string playerToPrince = "playerTo";
	std::string playerToKing = "playerTo";

	Card devinerCarte;	

};

#endif//Terminator


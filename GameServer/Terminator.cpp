#include "Terminator.h"
#include <random>
#include <algorithm>
#include <iostream>
#include "../GameCommon/GameUtils.h"


Terminator::Terminator(const std::string& name)
	: InfSup_Bot(name) 
{
}


Card Terminator::ChoisirCarte() 
{
	//PrintPlayedCard();
	if (firstRound) {
		return PlayLowest();
	}
	if (inHand(CardType::Princess)) {
		return PlayLowest();
	}
	else if (inHand(CardType::Countess)) {
		return PlayLowest();
	}
	else if (inHand(CardType::King)) {
			return Think();
	}
	else if (inHand(CardType::Prince)) {
		if (inHandTwice(CardType::Prince))
			return ThinkPrince();
		else
			return Think();
	}
	else if (inHand(CardType::Handmaiden)) {
		if (inHandTwice(CardType::Handmaiden))
			return PlayHandmaiden();
		else
			return Think();
	}
	else if (inHand(CardType::Baron)) {
		if (inHandTwice(CardType::Baron))
			return ThinkBaron();
		else
			return Think();
	}
	else if (inHand(CardType::Priest)) {
		if (inHandTwice(CardType::Priest))
			return ThinkPriest();
		else
			return Think();
	}
	else if (inHand(CardType::Guard)) {
		if (inHandTwice(CardType::Guard))
			return ThinkGuard();
		else
			return Think();
	}
	return PlayUnknown();
}


std::string Terminator::ChoisirJoueur(PlayersContainer& vectorPlayer, int nbPlayers) 
{
	if (toGuard) {
		toGuard = false;
		return playerToGuard;
	}
	else if (toPriest) {
		toPriest = false;
		return playerToPriest;
	}
	else if (toBaron) {
		toBaron = false;
		return playerToBaron;
	}
	else if (toPrince) {
		toPrince = false;
		return playerToPrince;
	}
	else if (toKing) {
		toKing = false;
		return playerToKing;
	}
	else {
		//InfSup_Bot b = { "OneShot" };
		return InfSup_Bot::ChoisirJoueur(vectorPlayer,nbPlayers);
	}
}


Card Terminator::DevinerCarte()
{
	return devinerCarte;
}


Card Terminator::PlayNotPrincess() {
	Card c = playerDeck.front();
	if (playerDeck.front().type == CardType::Princess) {
		c = playerDeck.back();
	}
	return c;
}

Card Terminator::PlayLowest()
{
	Card c = playerDeck.front();
	if (Utils::GetCardValue(playerDeck.front().type) >Utils::GetCardValue(playerDeck.back().type)) {
		c = playerDeck.back();
	}
	
	switch (c.type)
	{
	case CardType::None:       return ThinkUnknown();
	case CardType::Guard:      return ThinkGuard();
	case CardType::Priest:     return ThinkPriest();
	case CardType::Baron:      return ThinkBaron();
	case CardType::Handmaiden: return ThinkHandmaiden();
	case CardType::Prince:     return ThinkPrince();
	case CardType::King:       return ThinkKing();
	case CardType::Countess:   return ThinkCountess();
	default:                   return ThinkUnknown();
	}

}

int Terminator::CardsLeftPlayed(CardType t)
{
	int nb = 0;
	for (unsigned int i = 0; (!playedCard.empty()) && i < playedCard.size(); i++) {
		for (unsigned int j = 0; j < playedCard.at(i).cards.size(); j++) {
			if (playedCard.at(i).cards.at(j).type == t) {
				nb++;
			}
		}
	}
	return nb;
}



Card Terminator::Think()
{

	if (inHand(CardType::Baron) && GoodPlayBaron())
	{
		return ThinkBaron();
	}

	return PlayLowest();
}


Card Terminator::ThinkGuard()
{
	if (firstRound) {
		firstRound = false;
		if (playedCard.at(0).j->GetName() != GetName()) {
			playerToGuard = playedCard.at(0).j->GetName();
		}
		else {
			playerToGuard = playedCard.at(1).j->GetName();
		}
		
		devinerCarte = { CardType::Princess,2 };
		toGuard = true;
		return PlayGuard();
	}

	int indice = GetIndiceJoueurLastPlayedCardHighest();

	playerToGuard = playedCard.at(indice).j->GetName();
	CardType t1 = playedCard.at(indice).cards.back().type;	//prend la derniere carte la plus grande jouee
	indice = Utils::GetCardValue(t1);	//indice devient l'indice de la carte t1
	std::string s = std::to_string(indice+1);
	CardType t = Utils::CardTypeFromString(s);

		int nbCardMax;

		do {
			std::string s1 = std::to_string(indice+1);
			t = Utils::CardTypeFromString(s1);
			if (indice + 1 > 5) {
				nbCardMax = 1;
			}
			else if (indice + 1 > 1) {
				nbCardMax = 2;
			}
			else {
				nbCardMax = 5;
			}

			for (unsigned int i = 0; (!playedCard.empty()) && i < playedCard.size(); i++) {
				for (unsigned int j = 0; j < playedCard.at(i).cards.size(); j++) {
					if (playedCard.at(i).cards.at(j).type == t) {
						
						nbCardMax--;
					}
				}
			}
			indice++;
		} while (nbCardMax < 1);	//Verifie que les cartes a indice +1 n'ont pas toutes ete joues

		std::string s2 = std::to_string(indice);
		devinerCarte = { Utils::CardTypeFromString(s2), static_cast<Card::Strength>(indice) };
	toGuard = true;
	return PlayGuard();
}


Card Terminator::ThinkPriest()
{
	int indice = GetIndiceJoueurLastPlayedCardHighest();
	firstRound = false;

	playerToPriest = playedCard.at(indice).j->GetName();

	toPriest = true;
	return PlayPriest();
}


Card Terminator::ThinkBaron()
{
	int indice = GetIndiceJoueurLastPlayedCardLowest();
	firstRound = false;

	playerToBaron = playedCard.at(indice).j->GetName();

	toBaron = true;
	return PlayBaron();
}


Card Terminator::ThinkHandmaiden()
{
	firstRound = false;
	return PlayHandmaiden();
}


Card Terminator::ThinkPrince()
{
	int indice = GetIndiceJoueurLastPlayedCardHighest();
	firstRound = false;

	playerToPrince = playedCard.at(indice).j->GetName();

	toPrince = true;
	return PlayPrince();
}


Card Terminator::ThinkKing()
{
	int indice = GetIndiceJoueurLastPlayedCardHighest();
	firstRound = false;

	playerToKing = playedCard.at(indice).j->GetName();

	toKing = true;
	return PlayKing();
}


Card Terminator::ThinkCountess()
{
	firstRound = false;
	return PlayCountess();
}


Card Terminator::ThinkUnknown()
{
	firstRound = false;
	return PlayUnknown();
}



bool Terminator::inHand(CardType t) 
{
	return playerDeck.front().type == t || playerDeck.back().type == t;
}


bool Terminator::inHandTwice(CardType t)
{
	return playerDeck.front().type == t && playerDeck.back().type == t;
}



int Terminator::GetIndiceJoueurLastPlayedCardHighest()
{
	int premier = 0;
	int courant = 0;
	int indice = 0;
	
	if (!firstRound) {
		for (unsigned int i = 0; i < playedCard.size(); i++) {	//Choisit le joueur qui a joue la carte la + grande
			if ((playedCard.at(i).j->GetName() != GetName()) && playedCard.at(i).j->GetPlayerProtection() == false && playedCard.at(i).j->isDead == false) {
				
				courant = Utils::GetCardValue(playedCard.at(i).cards.back().type);
				
				if (courant > premier) {
					premier = courant;
					indice = i;
				}
			}
		}
	}
	else {
		if (playedCard.at(0).j->GetName() != GetName()) {
			return 0;
		}
		else {
			return 1;
		}
	}

	return indice;
}

int Terminator::GetIndiceJoueurLastPlayedCardLowest()
{
	int premier = 0;
	int courant = 0;
	int indice = 0;

	if (!firstRound) {
		for (unsigned int i = 0; (!playedCard.empty()) && i < playedCard.size(); i++) {	//Choisit le joueur qui a joue la carte la - grande
			if (playedCard.at(i).j->GetName() != GetName() && playedCard.at(i).j->GetPlayerProtection() != true && playedCard.at(i).j->isDead != true) {
				courant = Utils::GetCardValue(playedCard.at(i).cards.back().type);
				if (courant < premier) {
					premier = courant;
					indice = i;
				}
			}
		}
	}
	else {
		if (playedCard.at(0).j->GetName() != GetName()) {
			return 0;
		}
		else {
			return 1;
		}
	}
	return indice;
}



bool Terminator::GoodPlayBaron()
{
	if (inHand(CardType::Princess) || inHand(CardType::Countess) || inHand(CardType::King) || inHand(CardType::Prince)) {
		return true;
	}
	return false;
}


Card Terminator::PlayGuard() {
	return TakeCardByName("Guard");
}


Card Terminator::PlayPriest() {
	return TakeCardByName("Priest");	
}


Card Terminator::PlayBaron() {
	return TakeCardByName("Baron");
}


Card Terminator::PlayHandmaiden() {
	return TakeCardByName("Handmaiden");
}


Card Terminator::PlayPrince() {
	return TakeCardByName("Prince");
}


Card Terminator::PlayKing() {
	return TakeCardByName("King");
}


Card Terminator::PlayCountess() {
	return TakeCardByName("Countess");
}

Card Terminator::PlayUnknown()
{
	//InfSup_Bot b = { "OneShot" };
	return InfSup_Bot::ChoisirCarte();
}

void Terminator::PrintPlayedCard()
{
	std::cout << "+++++++++++++++++" << std::endl;
	for (unsigned int i = 0; i < playedCard.size(); i++) {
		std::cout << playedCard.at(i).j->GetName() << std::endl;
		for (unsigned int j = 0; j < playedCard.at(i).cards.size(); j++) {
			std::cout << Utils::CardTypeToString(playedCard.at(i).cards.at(j).type) << std::endl;
		}
	}
	std::cout << "-----------------" << std::endl;
}
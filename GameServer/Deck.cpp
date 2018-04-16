#include "Deck.h"
#include <random>
#include <algorithm>
#include <iostream>

Deck::Deck()
{
    _initDeck();
}

void Deck::_initDeck()
{
    m_deck.clear();
    m_deck.insert(m_deck.begin(), 5, {CardType::Guard, 1});   // begin() 5x iteration avec une carte de type Guard
    m_deck.insert(m_deck.begin(), 2, {CardType::Priest, 2});
    m_deck.insert(m_deck.begin(), 2, {CardType::Baron, 3});
    m_deck.insert(m_deck.begin(), 2, {CardType::Handmaiden, 4});
    m_deck.insert(m_deck.begin(), 2, {CardType::Prince, 5});
    m_deck.insert(m_deck.begin(), 1, {CardType::King, 6});
    m_deck.insert(m_deck.begin(), 1, {CardType::Countess, 7});
    m_deck.insert(m_deck.begin(), 1, {CardType::Princess, 8});
    //
    ShuffleDeck();
}

Card Deck::PickCard()
{
    Card toPick = m_deck.back();     
    m_deck.pop_back();
    return toPick;
}

bool Deck::IsEmpty() const
{
    return m_deck.empty();
}

int Deck::SizeDeck() const
{
    return m_deck.size();
}

void Deck::ShuffleDeck() 
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(m_deck.begin(), m_deck.end(), g);
}

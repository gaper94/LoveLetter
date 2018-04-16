#ifndef GAME_H
#define GAME_H

#include <vector>
#include <functional>
#include "../Network/IConnection.h"
#include "Joueur.h"
#include "Bot_Random.h"
#include "Deck.h"

class ServerGame
{
public:
    using Msg = IConnection::Msg;
    using Player = Joueur::Player;
    using PlayerPtr = Joueur::PlayerPtr;
    using PlayersContainer = Joueur::PlayersContainer;
    using AIPlayer = BotRandom;
    using MsgSender = std::function<void(const IConnection::Msg&)>;

    enum class GameState
    {
        Waiting,
        InProcess,
    };

    void Init(MsgSender msgSender);
    void StartGame();
    void ForceStopGame();
    void InitPlayers(const Msg& msg);
    bool CanStartGame();
    void Update();

private:
    void _startGame();
    void _playRound();
    bool _checkForWinner();
    PlayersContainer::iterator _getWinnerPos();
    PlayerPtr _getWinner();
    void _prepareForNextRound();
    void _addAIPlayers();
    //
    int  _playersAlive() const;
    int _getPlayerPosition(PlayerPtr player);
    bool _allProtected(PlayerPtr player);
    void _cardEffectCheck(const Card& c, Deck& deck, PlayerPtr player, int pos);
    void _printDefausse();
    void _sendMsg(const IConnection::Msg& msg);

    struct PlayedCards
    {
        PlayerPtr player;
        Deck::DeckStorage cards;
    };

    int32_t m_numberOfPlayers = 0;
    PlayersContainer m_players;
    Card m_defausse;
    std::vector<PlayedCards> m_playedCards;
    GameState m_gameState = GameState::Waiting;
    MsgSender m_msgSender = nullptr;
};

#endif // GAME_H

#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../Network/IConnection.h"
#include "../to_be_integrated/Joueur.h"
#include "../to_be_integrated/Bot_Random.h"
#include "../to_be_integrated/Deck.h"

class ServerGame
{
public:
    using Msg = IConnection::Msg;
    using Player = Joueur::Player;
    using PlayerPtr = Joueur::PlayerPtr;
    using PlayersContainer = Joueur::PlayersContainer;
    using AIPlayer = BotRandom;

    enum class GameState
    {
        Waiting,
        InProcess,
    };

    struct PlayedCards
    {
        PlayerPtr player;
        Deck::DeckStorage cards;
    };

    void StartGame();
    void ForceStopGame();
    void InitPlayers(const Msg& msg);
    bool CanStartGame();

private:
    void _startGame();
    void _playRound(const Deck& deck);
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

    int32_t m_numberOfPlayers = 0;
    PlayersContainer m_players;
    Card m_defausse;
    std::vector<PlayedCards> m_playedCards;
    GameState m_gameState = GameState::Waiting;
};

#endif // GAME_H

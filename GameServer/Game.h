#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../Network/IConnection.h"
#include "../to_be_integrated/Joueur.h"
#include "../to_be_integrated/Bot_Random.h"

struct PlayedCards
{
    Joueur* j;
    std::vector<Card> cards;
};

class ServerGame
{
public:
    using Msg = IConnection::Msg;
    using Player = Joueur;
    using AIPlayer = BotRandom;
    using PlayerPtr = std::shared_ptr<Joueur>;
    using PlayersContainer = std::vector<PlayerPtr>;

    enum class GameState
    {
        Waiting,
        InProcess,
    };

    int  PlayersAlive() const;
    void StartGame();
    void ForceStopGame();
    void InitPlayers(const Msg& msg);
    bool CanStartGame();

    int GetPlayerPosition(Joueur* j);
    bool AllProtected(Joueur * moi);
    void CardEffectCheck(const Card& c, Deck * deck ,Joueur * j,int pos);
    void PrintDefausse();
private:
    void _startGame();
    void _playRound(const Deck& deck);
    bool _checkForWinner();
    PlayersContainer::iterator _getWinnerPos();
    PlayerPtr _getWinner();
    void _prepareForNextRound();
    void _addAIPlayers();

    std::vector <Joueur*> vectorPlayers;
    Card defausse;
    std::vector<PlayedCards> m_playedCards;
    //
    int32_t m_numberOfPlayers = 0;
    PlayersContainer m_players;
    GameState m_gameState = GameState::Waiting;
};

#endif // GAME_H

#ifndef GAME_DEFINITONS_H
#define GAME_DEFINITONS_H

#include <string>

enum class CardType
{
    None,
    Guard = 1,
    Priest,
    Baron,
    Handmaiden,
    Prince,
    King,
    Countess,
    Princess,
};

using Id = unsigned char;

enum class AIPlayerDifficulty
{
    Easy,
    Medium,
    Hard,
};

struct AIPlayerCfg
{
    std::string name;
    AIPlayerDifficulty difficulty = AIPlayerDifficulty::Easy;
};

#endif // GAME_DEFINITONS_H

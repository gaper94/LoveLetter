#ifndef GAME_DEFINITONS_H
#define GAME_DEFINITONS_H

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

#endif // GAME_DEFINITONS_H

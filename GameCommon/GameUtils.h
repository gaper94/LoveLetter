#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <string>
#include "GameDefinitions.h"

namespace Utils
{

std::string CardTypeToString(CardType);
CardType CardTypeFromString(const std::string&);

}

#endif // GAME_UTILS_H

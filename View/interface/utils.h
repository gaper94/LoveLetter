#ifndef UTILS_H
#define UTILS_H
#include <QString>
#include <string>
#include "../../Network/IConnection.h"
#include <functional>

using Msg = IConnection::Msg;
using MsgSender = std::function<void(const Msg&)>;

    extern QString name;
    extern int nb_players;
    extern std::string language; //used for setting the language

#endif // UTILS_H

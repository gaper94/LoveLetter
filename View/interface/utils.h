#ifndef UTILS_H
#define UTILS_H
#include <QString>
#include <string>
#include <functional>
#include "../../Network/IConnection.h"

extern QString name;
extern int nb_players;
extern std::string language;

using Msg = IConnection::Msg;
using MsgSender = std::function<void(const Msg&)>;

#endif // UTILS_H

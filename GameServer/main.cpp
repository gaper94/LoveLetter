#include "GameServer.h"
#include <thread>
#include <chrono>
//
#include "../Network/IConnection.h"

int main()
{
    GameServer gamerServer;
    if(gamerServer.Init({}) == false)
    {
        return 1;
    }
    //
    while(true)
    {
        gamerServer.Update();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
//    using Msg = IConnection::Msg;
//    Msg init;
//    init.name = "players_config";
//    int32_t numberOfPlayers = 3;
//    init.AddValue("number_of_players", numberOfPlayers);

//    std::string playerName = "Ivan";
//    init.AddValue("player_name", playerName);

//    gamerServer._onGameControllerMsgReceived(0, init);
//    Msg start;
//    start.name = "start_game";
//    gamerServer._onGameControllerMsgReceived(0, start);
    return 0;
}

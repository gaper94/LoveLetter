#include "GameServer.h"
#include <thread>
#include <chrono>

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
    return 0;
}

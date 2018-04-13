#include "GameController.h"
#include <thread>
#include <chrono>

int main()
{
    GameController gameController;
    if(gameController.Init({}) == false)
    {
        return 1;
    }
    //
    while(true)
    {
        gameController.Update();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
    return 0;
}

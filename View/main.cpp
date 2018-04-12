#include "View.h"
#include <thread>
#include <chrono>

int main()
{

    View view;
    if(view.Init({}) == false)
    {
        return 1;
    }
    //
    while(true)
    {
        view.Update();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
    return 0;
}

#include "mainwindow.h"
#include "View.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    View view(argc, argv);
    if(view.Init({}) == false)
    {
        return 1;
    }

    bool timeToQuit = false;
    while(timeToQuit == false)
    {
        view.Update();
    }
    return 0;
}


// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include <iostream>
#include <ctime>
#include <random>

#include "CoreMinimal.h"
#include "WindowsConsoleScreen.h"

#include "CrazyTanks.h"

using namespace std;

const int FPS_MAX = 10;

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    WindowsConsoleScreen screen;
    screen.setCursorVisible(false);

    double timeFrame = 0.0;
    clock_t currClock;
    clock_t prevClock = clock();

    CrazyTanks game;
    game.beginPlay();

    while (true)
    {
        if (timeFrame >= (1.0 / FPS_MAX))
        {  
            screen.clear();
            game.draw(screen);
            game.tick(static_cast<float>(timeFrame));
            timeFrame = 0.0;
        }

        currClock = clock();
        timeFrame += static_cast<double>(currClock - prevClock)
            / static_cast<double>(CLOCKS_PER_SEC);
        prevClock = currClock;
    }
    system("pause");
    return 0;
}
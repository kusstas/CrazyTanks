// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "CrazyTanks.h"
#include "WorldTanks.h"
#include "PlayerTank.h"

#include "Screen.h"

#include <string>

void CrazyTanks::beginPlay()
{
    Game::beginPlay();

    loadWorld<WorldTanks>();
}

void CrazyTanks::tick(float deltaTime)
{
    Game::tick(deltaTime);

    lives = PlayerTank::getInstance() != nullptr ? PlayerTank::getInstance()->getLives() : 0;
}

void CrazyTanks::draw(Screen& screen)
{
    Game::draw(screen);
    std::string str = "Lives: ";
    for (int i = 0; i < lives; i++)
        str += '#';
    screen.draw(50, 1, str.c_str());
}
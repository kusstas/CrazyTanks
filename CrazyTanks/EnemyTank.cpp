// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "EnemyTank.h"

#include "Pixel.h"


EnemyTank::EnemyTank(World& world) : Tank(world)
{
    indexTeam_ = 1;
}

Pixel EnemyTank::getDrawing() const
{
    Pixel p = Tank::getDrawing();
    p.setColorSymbol(COLOR_LIGHT_GREEN);
    return p;
}
// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "Wall.h"
#include "Pixel.h"

Wall::Wall(World& world) : GameObject(world)
{
    isStatic_ = true;
}

Pixel Wall::getDrawing() const
{
    return Pixel('@', COLOR_LIGHT_BLUE, COLOR_BLACK);
}
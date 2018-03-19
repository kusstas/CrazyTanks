// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "PlayerTank.h"
#include "PlayerController.h"

PlayerTank::PlayerTank(World& world) : Tank(world)
{
    maxDurationMove = 0.05f;

    controller_ = new PlayerController();
}
// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "PlayerTank.h"
#include "PlayerController.h"

PlayerTank::PlayerTank(World& world) : Tank(world)
{
    maxLives_ = 3;
    controller_ = new PlayerController();
    controller_->setPawn(*this);
}
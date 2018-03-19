// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "PlayerTank.h"
#include "PlayerController.h"

PlayerTank::PlayerTank(World& world) : Tank(world)
{
    controller_ = new PlayerController();
    controller_->setPawn(*this);
}
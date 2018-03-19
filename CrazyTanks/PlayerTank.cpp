// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "PlayerTank.h"
#include "PlayerController.h"

PlayerTank* PlayerTank::instance = nullptr;

PlayerTank::PlayerTank(World& world) : Tank(world)
{
    instance = this;
    maxDurationMove = 0.05f;

    controller_ = new PlayerController();
}

PlayerTank::~PlayerTank()
{
    instance = nullptr;
}

const PlayerTank* PlayerTank::getInstance()
{
    return instance;
}
// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef PLAYER_TANK_H
#define PLAYER_TANK_H

#include "Tank.h"

class PlayerTank : public Tank
{
public:
    PlayerTank(World& world);
};

#endif // !PLAYER_TANK_H
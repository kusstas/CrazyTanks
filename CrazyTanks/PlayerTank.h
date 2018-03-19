// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef PLAYER_TANK_H
#define PLAYER_TANK_H

#include "Tank.h"

class PlayerTank : public Tank
{
public:

    PlayerTank(World& world);
    ~PlayerTank();

    static const PlayerTank* getInstance();

public:

    static PlayerTank* instance;
};

#endif // !PLAYER_TANK_H
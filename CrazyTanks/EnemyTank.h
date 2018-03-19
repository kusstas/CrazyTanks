// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef ENEMY_TANK_H
#define ENEMY_TANK_H

#include "Tank.h"

class EnemyTank : public Tank
{
public:

    EnemyTank(World& world);
    
    virtual Pixel getDrawing() const override;
};

#endif // !ENEMY_TANK_H
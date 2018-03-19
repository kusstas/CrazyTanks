// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef ENEMY_TANK_H
#define ENEMY_TANK_H

#include "Tank.h"

class AiController;

class EnemyTank : public Tank
{
public:

    EnemyTank(World& world);
    ~EnemyTank();
    
    virtual Pixel getDrawing() const override;

    virtual void tick(float deltaTime) override;
   
    virtual void onOverlap(GameObject& object, DVector2D location);
    virtual void onOverstepBorder();

    static int getCount();

private:

    static int count;

    AiController* aiController_;
};

#endif // !ENEMY_TANK_H
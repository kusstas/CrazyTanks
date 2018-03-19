// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameObject.h"


class Tank;

class Projectile : public GameObject
{
public :

    Projectile(World& world);

    virtual void tick(float deltaTime) override;
    virtual void onOverstepBorder() override;
    virtual void onOverlap(GameObject& object, DVector2D location) override;
    virtual Pixel getDrawing() const override; 
    void SetTankOwner(Tank& tank);

private:

    float durationMove;

    Tank* owner;
    
};

#endif // !PROJECTILE_H
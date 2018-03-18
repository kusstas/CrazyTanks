// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef TANK_H
#define TANK_H

#include "GameObject.h"

class Tank : public GameObject
{
public:

    Tank(World& world);

    virtual void beginPlay() override;
    virtual void tick(float deltaTime);
    virtual void onOverlap(GameObject& object, DVector2D location) override;


    virtual Pixel getDrawing() const override;

    int getIndexTeam() const;
    int getLives() const;
    int getMaxLives() const;

    void setIndexTeam(int indexTeam);

    void startMove(RotationZ direct);
    void stopMove();
     
    void fire();

protected:

    int maxLives_;
    int lives_;

    float durationMove;

    int indexTeam_;
};

#endif // !TANK_H
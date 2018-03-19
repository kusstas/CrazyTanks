// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef TANK_H
#define TANK_H

#include "GameObject.h"

class Controller;

class Tank : public GameObject
{
public:

    Tank(World& world);
    virtual ~Tank();

    virtual void beginPlay() override;
    virtual void tick(float deltaTime);

    virtual Pixel getDrawing() const override;

    int getIndexTeam() const;
    int getLives() const;
    int getMaxLives() const;

    void setIndexTeam(int indexTeam);

    void startMove(RotationZ direct);
    void stopMove();
     
    void fire();
    void applyDamage();

protected:

    int maxLives_;
    int lives_;

    float durationMove;
    float maxDurationMove;
    float coolDown;
    float maxCoolDown;
    bool isMove_;

    int indexTeam_;

    Controller* controller_;
};

#endif // !TANK_H
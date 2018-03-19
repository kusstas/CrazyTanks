// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef AI_CONTROLLER_H
#define AI_CONTROLLER_H

#include "Controller.h"
#include "CoreMinimal.h"

class AiController : public Controller
{
public:

    virtual void tick(float deltaTime) override;

    void onCollision();

private:

    RotationZ moveDirect_;
    float timerChange;

    void changeDirect();
};

#endif // !AI_CONTROLLER_H
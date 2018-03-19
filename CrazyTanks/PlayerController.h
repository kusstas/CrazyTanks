// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Controller.h"

class PlayerController : public Controller
{
public:

    virtual void tick(float deltaTime) override;

};

#endif // !PLAYER_CONTROLLER_H
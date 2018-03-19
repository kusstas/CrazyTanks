// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "AiController.h"

#include "Tank.h"
#include "PlayerTank.h"

#include <random>

void AiController::tick(float deltaTime)
{
    timerChange += deltaTime;
    if (timerChange > 1.5f)
    {
        changeDirect();
        timerChange = 0.0f;
    }

    PlayerTank* pt;
    pt = dynamic_cast<PlayerTank*>(pawn_->trace(moveDirect_, 15));

    if (pt != nullptr)
    {
        pawn_->fire();
    }
    else
    {

    }

    

    pawn_->startMove(moveDirect_);
}

void AiController::onCollision()
{
    changeDirect();
}

void AiController::changeDirect()
{
    RotationZ r;
    do {
        r = static_cast<RotationZ>(rand() % 4);
    } while (r == moveDirect_);
    moveDirect_ = r;
}
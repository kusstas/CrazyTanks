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

    
    PlayerTank* ptUp = dynamic_cast<PlayerTank*>(pawn_->trace(ROTATION_Z_UP, 15));
    PlayerTank* ptDn= dynamic_cast<PlayerTank*>(pawn_->trace(ROTATION_Z_DOWN, 15));
    PlayerTank* ptLt = dynamic_cast<PlayerTank*>(pawn_->trace(ROTATION_Z_LEFT, 15));
    PlayerTank* ptRt = dynamic_cast<PlayerTank*>(pawn_->trace(ROTATION_Z_RIGHT, 15));

    bool isFire = false;

    if (ptUp != nullptr)
    {
        pawn_->setRotationZ(ROTATION_Z_UP);
        isFire = true;
    }
    else if (ptDn != nullptr)
    {
        pawn_->setRotationZ(ROTATION_Z_DOWN);
        isFire = true;
    }
    else if (ptLt != nullptr)
    {
        pawn_->setRotationZ(ROTATION_Z_LEFT);
        isFire = true;
    }
    else if (ptRt != nullptr)
    {
        pawn_->setRotationZ(ROTATION_Z_RIGHT); 
        isFire = true;
    }
    else
    {
        pawn_->startMove(moveDirect_);
    }

    if (isFire)
    {
        pawn_->fire();
        timerChange = 0.0f;
    }
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
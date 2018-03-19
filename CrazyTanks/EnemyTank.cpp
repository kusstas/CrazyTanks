// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "EnemyTank.h"

#include "AiController.h"
#include "World.h"

#include "Pixel.h"


EnemyTank::EnemyTank(World& world) : Tank(world)
{
    maxDurationMove = 0.25f;
    indexTeam_ = 1;

    controller_ = new AiController();
}

Pixel EnemyTank::getDrawing() const
{
    Pixel p = Tank::getDrawing();
    p.setColorSymbol(COLOR_LIGHT_GREEN);
    return p;
}

void EnemyTank::tick(float deltaTime)
{
    aiController_ = dynamic_cast<AiController*>(controller_);

    Tank::tick(deltaTime);
}

void EnemyTank::onOverlap(GameObject& object, DVector2D location)
{
    Tank::onOverlap(object, location);

    if (aiController_)
        aiController_->onCollision();
}

void EnemyTank::onOverstepBorder()
{
    Tank::onOverstepBorder();

    if (aiController_)
        aiController_->onCollision();
}
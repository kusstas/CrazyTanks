// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "Tank.h"
#include "World.h"
#include "Projectile.h"
#include "Controller.h"

#include "Pixel.h"

Tank::Tank(World& world) : GameObject(world)
{
    maxDurationMove = 0.2f;
    maxCoolDown = 0.4f;
    maxLives_ = 3;
    indexTeam_ = 0;

    coolDown = 0.0f;
    durationMove = 0.0f;
    isMove_ = false;

    controller_ = nullptr;
}

Tank::~Tank()
{
    if (controller_ != nullptr)
        delete controller_;
}

void Tank::beginPlay()
{
    GameObject::beginPlay();

    lives_ = maxLives_;
    
    if (controller_ != nullptr)
        controller_->setPawn(*this);
}

void Tank::tick(float deltaTime)
{
    if (controller_ != nullptr)
        controller_->tick(deltaTime);

    if (isMove_)
    {
        durationMove += deltaTime;
        if (durationMove >= maxDurationMove)
        {
            durationMove = 0;
            GameObject::move(getRotationZ(), 1);
        }
    }

    coolDown -= deltaTime;
    GameObject::tick(deltaTime);
}

Pixel Tank::getDrawing() const
{
    Pixel p;
    p.setColorSymbol(COLOR_LIGHT_RED);
    switch (getRotationZ())
    {
    case ROTATION_Z_DOWN:
        p.setSymbol('V');
        break;
    case ROTATION_Z_UP:
        p.setSymbol('A');
        break;
    case ROTATION_Z_LEFT:
        p.setSymbol('<');
        break;
    case ROTATION_Z_RIGHT:
        p.setSymbol('>');
        break;
    }
    return p;
}

int Tank::getIndexTeam() const
{
    return indexTeam_;
}

int Tank::getLives() const
{
    return lives_;
}

int Tank::getMaxLives() const
{
    return maxLives_;
}

void Tank::setIndexTeam(int indexTeam)
{
    indexTeam_ = indexTeam;
}

void Tank::startMove(RotationZ direct)
{
    isMove_ = true;
    setRotationZ(direct);
}

void Tank::stopMove()
{
    isMove_ = false;
    durationMove = 0;
}

void Tank::fire()
{
    if (coolDown <= 0.0f)
    {
        Projectile* p = getWorld()->createGameObject<Projectile>();
        p->SetTankOwner(*this);

        p->setRotationZ(getRotationZ());
        p->setLocation(getLocation());

        coolDown = maxCoolDown;
    }
}

void Tank::applyDamage()
{
    lives_--;
    if (lives_ == 0)
        destroy();
}
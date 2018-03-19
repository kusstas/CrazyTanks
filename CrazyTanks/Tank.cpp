﻿// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "Tank.h"
#include "World.h"
#include "Projectile.h"

#include "Pixel.h"

Tank::Tank(World& world) : GameObject(world)
{
    maxLives_ = 1;
    indexTeam_ = 0;
    durationMove = 0;
    isMove_ = false;
}

void Tank::beginPlay()
{
    GameObject::beginPlay();

    lives_ = maxLives_;
}

void Tank::tick(float deltaTime)
{
    if (isMove_)
    {
        durationMove += deltaTime;
        if (durationMove > 0.05f)
        {
            durationMove = 0;
            GameObject::move(getRotationZ(), 1);
        }       
    }

    coolDown -= deltaTime;
    GameObject::tick(deltaTime);
}

void Tank::onOverlap(GameObject& object, DVector2D location)
{
}

Pixel Tank::getDrawing() const
{
    switch (getRotationZ())
    {
    case ROTATION_Z_DOWN:
        return Pixel('V', COLOR_LIGHT_RED, COLOR_BLACK);
    case ROTATION_Z_UP:
        return Pixel('A', COLOR_LIGHT_RED, COLOR_BLACK);
    case ROTATION_Z_LEFT:
        return Pixel('<', COLOR_LIGHT_RED, COLOR_BLACK);
    case ROTATION_Z_RIGHT:
        return Pixel('>', COLOR_LIGHT_RED, COLOR_BLACK);
    }
    return Pixel('X', COLOR_LIGHT_RED, COLOR_BLACK);
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

        p->move(getRotationZ(), 1);

        coolDown = 0.2f;
    }
}
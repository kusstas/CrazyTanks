// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "Tank.h"
#include "Pixel.h"

Tank::Tank(World& world) : GameObject(world)
{
    maxLives_ = 1;
    indexTeam_ = 0;
    durationMove = 0;
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
        if (durationMove > 0.1f)
        {
            durationMove = 0;
            DVector2D newLocation;
            switch (getRotationZ())
            {
            case ROTATION_Z_DOWN:
                newLocation = getLocation() + DVector2D(0, 1);
                break;
            case ROTATION_Z_UP:
                newLocation = getLocation() + DVector2D(0, -1);
                break;
            case ROTATION_Z_LEFT:
                newLocation = getLocation() + DVector2D(-1, 0);
                break;
            case ROTATION_Z_RIGHT:
                newLocation = getLocation() + DVector2D(1, 0);
                break;
            }
            setLocation(newLocation);
        }       
    }

    GameObject::tick(deltaTime);
}

void Tank::onOverlap(GameObject& object, DVector2D location)
{
    if (object.isBlockObject() && isMove_)
    {
        if (getLocation() == object.getLocation())
        {
            DVector2D newLocation;
            switch (getRotationZ())
            {
            case ROTATION_Z_DOWN:
                newLocation = getLocation() + DVector2D(0, -1);
                break;
            case ROTATION_Z_UP:
                newLocation = getLocation() + DVector2D(0, 1);
                break;
            case ROTATION_Z_LEFT:
                newLocation = getLocation() + DVector2D(1, 0);
                break;
            case ROTATION_Z_RIGHT:
                newLocation = getLocation() + DVector2D(-1, 0);
                break;
            }
            setLocation(newLocation);
        }
    }
}

Pixel Tank::getDrawing() const
{
    switch (getRotationZ())
    {
    case ROTATION_Z_DOWN:
        return Pixel('Y', COLOR_LIGHT_RED, COLOR_BLACK);
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

void Tank::move(RotationZ direct)
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
}
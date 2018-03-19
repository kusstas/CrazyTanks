// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "GameObject.h"
#include "World.h"

#include "Pixel.h"

GameObject::GameObject(World& world)
    : world(&world)
{
    active_ = true;
    isStatic_ = false;
    blockObject_ = true;
    shouldBeDestroyed_ = false;
}

GameObject::~GameObject()
{
}

bool GameObject::isActive() const
{
    return active_;
}

bool GameObject::isStatic() const
{
    return isStatic_;
}

bool GameObject::isBlockObject() const
{
    return blockObject_;
}

bool GameObject::isShouldBeDestroyed() const
{
    return shouldBeDestroyed_;
}

const DVector2D& GameObject::getLocation() const
{
    return location_;
}

const DVector2D& GameObject::getPrevLocation() const
{
    return prevLocation_;
}

RotationZ GameObject::getRotationZ() const
{
    return rotationZ_;
}

World* GameObject::getWorld() const
{
    return world;
}

void GameObject::setActive(bool active)
{
    active_ = active;
}

void GameObject::setBlockObject(bool blockObject)
{
    blockObject_ = blockObject;
}

void GameObject::setLocation(const DVector2D& locaction)
{
    location_ = locaction;
    if (isStatic())
        prevLocation_ = location_;
}

void GameObject::setLocation(int x, int y)
{
    setLocation(DVector2D(x, y));
}

void GameObject::setRotationZ(RotationZ rotationZ)
{
    rotationZ_ = rotationZ;
}

void GameObject::move(RotationZ direct, int scale)
{
    DVector2D newLoc;
    switch (getRotationZ())
    {
    case ROTATION_Z_DOWN:
        newLoc = getLocation() + DVector2D(0, scale);
        break;
    case ROTATION_Z_UP:
        newLoc = getLocation() + DVector2D(0, -scale);
        break;
    case ROTATION_Z_LEFT:
        newLoc = getLocation() + DVector2D(-scale, 0);
        break;
    case ROTATION_Z_RIGHT:
        newLoc = getLocation() + DVector2D(scale, 0);
        break;
    }
    setLocation(newLoc);
}

Pixel GameObject::getDrawing() const
{
    return Pixel('#', COLOR_LIGHT_GREEN, COLOR_BLACK);
}

void GameObject::beginPlay()
{
}

void GameObject::tick(float deltaTime)
{
    DVector2D sizeWorld = world->getSize();

    // Ban of going beyond the borders of the world

    bool isOverstep = false;
    if (location_.x < 0) {
        location_.x = 0;
        isOverstep = true;
    }
    else if (location_.x > sizeWorld.x - 1) {
        location_.x = sizeWorld.x - 1;
        isOverstep = true;
    }

    if (location_.y < 0) {
        location_.y = 0;
        isOverstep = true;
    }
    else if (location_.y > sizeWorld.y - 1) {
        location_.y = sizeWorld.y - 1;
        isOverstep = true;
    }

    if (isOverstep)
        onOverstepBorder();
}

GameObject* GameObject::trace(RotationZ direct, int distance)
{
    DVector2D tracer;
    switch (direct)
    {
    case ROTATION_Z_DOWN:
        tracer = DVector2D(0, 1);
        break;
    case ROTATION_Z_UP:
        tracer = DVector2D(0, -1);
        break;
    case ROTATION_Z_LEFT:
        tracer = DVector2D(-1, 0);
        break;
    case ROTATION_Z_RIGHT:
        tracer = DVector2D(1, 0);
        break;
    }

    for (int i = 1; i <= distance; i++)
    {
        DVector2D loc = tracer * static_cast<float>(i);
        loc += location_;
        GameObject* goRes = getWorld()->getGameObjectFromLocation(loc);

        if (goRes != nullptr)
            return goRes;
    }
    return nullptr;
}

void GameObject::physTick()
{
    prevLocation_ = location_;
}

void GameObject::onOverlap(GameObject& object, DVector2D location)
{
}

void GameObject::onOverstepBorder()
{
}

void GameObject::destroy()
{
    shouldBeDestroyed_ = true;
}
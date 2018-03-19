#include "Projectile.h"

#include "Pixel.h"


Projectile::Projectile(World& world) : GameObject(world)
{
    blockObject_ = false;
}

void Projectile::tick(float deltaTime)
{
    durationMove += deltaTime;
    if (durationMove > 0.025f)
    {
        durationMove = 0;
        GameObject::move(getRotationZ(), 1);
    }
    
    GameObject::tick(deltaTime);
}

void Projectile::onOverstepBorder()
{
    destroy();
}

void Projectile::onOverlap(GameObject& object, DVector2D location)
{
    destroy();
}

Pixel Projectile::getDrawing() const
{
    return Pixel('.', COLOR_WHITE, COLOR_BLACK);
}

void Projectile::SetTankOwner(Tank& tank)
{
    owner = &tank;
}
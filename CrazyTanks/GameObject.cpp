#include "GameObject.h"

GameObject::GameObject(World& worldOwner)
{
	worldOwner_ = &worldOwner;
}

bool GameObject::isActive() const
{
	return active_;
}

const DVector2D& GameObject::getLocation() const
{
	return location_;
}

RotationZ GameObject::getRotationZ() const
{
	return rotationZ_;
}

void GameObject::setActive(bool value)
{
	visibility_ = newVisibility;
}

void GameObject::setLocation(const DVector2D& newLocation)
{
	location_ = newLocation;
}

void GameObject::setRotationZ(RotationZ newRotationZ)
{
	rotationZ_ = newRotationZ;
}

void GameObject::tick(float deltaTime)
{

}

void GameObject::destroy()
{

}
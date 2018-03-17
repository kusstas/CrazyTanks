#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "World.h"
#include "Vector2D.h"
#include "RotationZ.h"

class GameObject
{
public:

	GameObject(World& worldOwner, const DVector2D& location, RotationZ);
	virtual ~GameObject();

	bool isActive() const;
	const DVector2D& getLocation() const;
	RotationZ getRotationZ() const;

	void setActive(bool value);
	void setLocation(const DVector2D& newLocation);
	void setRotationZ(RotationZ newRotationZ);

	virtual void tick(float deltaTime);

	void destroy();

private:

	World * worldOwner_;

	bool active_;

	DVector2D location_;
	RotationZ rotationZ_;

};

#endif // !GAME_OBJECT_H
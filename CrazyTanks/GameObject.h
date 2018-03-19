// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "CoreMinimal.h"

class World;
class Pixel;

// Evetything in the world is GameObject
class GameObject
{
public:

    GameObject(World& world);

    virtual ~GameObject();

    bool isActive() const;
    bool isStatic() const;
    bool isBlockObject() const;
    bool isShouldBeDestroyed() const;

    const DVector2D& getLocation() const;
    const DVector2D& getPrevLocation() const;
    RotationZ getRotationZ() const;

    void setActive(bool active);
    void setBlockObject(bool blockObject);

    void setLocation(const DVector2D& location);
    void setLocation(int x, int y);
    void setRotationZ(RotationZ rotationZ);

    void move(RotationZ direct, int scale);

    // Return pixel for draw him on screen
    virtual Pixel getDrawing() const;

    virtual void beginPlay();

    // Execute each draw-tick (except for static-objects)
    virtual void tick(float deltaTime);

    // Update previos location
    virtual void physTick();

    // Call on overlap object
    virtual void onOverlap(GameObject& object, DVector2D location);

    // Call on overstep border of world
    virtual void onOverstepBorder();

    // Destroy object and remove from current world
    void destroy();

protected:

    World* getWorld() const;

    bool active_;
    bool isStatic_;
    bool blockObject_;

private:

    World * world;

    DVector2D location_;
    DVector2D prevLocation_;
    RotationZ rotationZ_;

    bool shouldBeDestroyed_;

};

#endif // !GAME_OBJECT_H
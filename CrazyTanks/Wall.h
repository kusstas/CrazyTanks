// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef WALL_H
#define WALL_H

#include "GameObject.h"

class Wall : public GameObject
{
public:

    Wall(World& world);

    virtual Pixel getDrawing() const override;
};

#endif // !WALL_H
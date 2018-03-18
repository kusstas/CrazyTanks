// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef WORLD_TANKS_H
#define WORLD_TANKS_H

#include "World.h"

class Tank;

class WorldTanks : public World
{
public:

    WorldTanks();
    
    virtual void beginPlay() override;
    virtual void tick(float deltaTime) override;
    virtual void draw(Screen& screen) override;

protected:

    void drawBorder(Screen& screen) const;
    void generateWalls();
   
    Tank* tank;
};

#endif !WORLD_TANKS_H
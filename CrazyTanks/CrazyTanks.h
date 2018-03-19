// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef CRAZY_TANKS_H
#define CRAZY_TANKS_H

#include "Game.h"

class CrazyTanks : public Game
{
public:

    virtual void beginPlay() override;
    virtual void tick(float deltaTime) override;
    virtual void draw(Screen& screen) override;

private:

    int lives;
};

#endif // !CRAZY_TANKS_H
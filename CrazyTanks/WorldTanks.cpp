// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "WorldTanks.h"
#include "GameObject.h"
#include "PlayerTank.h"
#include "EnemyTank.h"
#include "Wall.h"

#include "Screen.h"
#include "Pixel.h"

#include <stdio.h>
#include <random>

WorldTanks::WorldTanks()
{
    offsetWorld_ = DVector2D(1, 1);
    size_ = DVector2D(40, 17);
}

void WorldTanks::beginPlay()
{
    generateTanks();
    generateWalls();
}

void WorldTanks::tick(float deltaTime)
{
    World::tick(deltaTime);
}

void WorldTanks::draw(Screen& screen)
{
    drawBorder(screen);
    World::draw(screen);
}

void WorldTanks::drawBorder(Screen& screen) const
{
    // draw horizontal borders
    for (int i = 0; i < size_.x + 2; i++)
    {
        Pixel wall('#', COLOR_LIGHT_GREEN, COLOR_BLUE);

        screen.draw(i, 0, wall);
        screen.draw(i, size_.y + 1, wall);
    }
    // draw vertical borders
    for (int i = 0; i < size_.y + 1; i++)
    {
        Pixel wall('#', COLOR_LIGHT_GREEN, COLOR_BLUE);

        screen.draw(0, i, wall);
        screen.draw(size_.x + 1, i, wall);
    }
}

void WorldTanks::generateWalls()
{
    int stepX = getSize().x / 3;
    int stepY = getSize().y / 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x1 = rand() % (stepX - 1);
            int y1 = rand() % (stepY - 1);

            int XorY = rand() % 2;

            if (XorY == 1)
            {
                int y2;
                y2 = rand() % (stepY - 1);

                if (y2 < y1)
                    swap(y2, y1);

                for (int k = y1; k <= y2; k++)
                {
                    DVector2D loc = DVector2D(x1 + stepX * i, k + stepY * j);

                    if (getGameObjectFromLocation(loc) == nullptr)
                    {
                        Wall* w = createGameObject<Wall>();
                        w->setLocation(loc);
                    }
                }
            }
            else
            {
                int x2;
                x2 = rand() % (stepX - 1);

                if (x2 < x1)
                    swap(x2, x1);

                for (int k = x1; k <= x2; k++)
                {
                    DVector2D loc = DVector2D(k + stepX * i, y1 + stepY * j);

                    if (getGameObjectFromLocation(loc) == nullptr)
                    {
                        Wall* w = createGameObject<Wall>();
                        w->setLocation(loc);
                    }
                }
            }
        }
    }
}

void WorldTanks::generateTanks()
{
    int stepX = getSize().x / 3;
    int stepY = getSize().y / 3;

    DVector2D loc;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {    
            loc.x = (rand() % (stepX - 1)) + stepX * i;
            loc.y = (rand() % (stepY - 1)) + stepY * j;

            Tank* t = createGameObject<EnemyTank>();
            t->setLocation(loc);
        }
    }

    loc.x = (rand() % (stepX - 1)) + stepX;
    loc.y = (rand() % (stepY - 1)) + stepY * 2;

    Tank* t = createGameObject<PlayerTank>();
    t->setLocation(loc);
}
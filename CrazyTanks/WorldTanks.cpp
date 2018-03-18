// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "WorldTanks.h"
#include "GameObject.h"
#include "Tank.h"
#include "Wall.h"

#include "Screen.h"
#include "Pixel.h"

#include <stdio.h>
#include <conio.h>
#include <random>

WorldTanks::WorldTanks()
{
    offsetWorld_ = DVector2D(1, 1);
    size_ = DVector2D(40, 17);
    tank = nullptr;
}

void WorldTanks::beginPlay()
{
    generateWalls();
    tank = createGameObject<Tank>();
    tank->setLocation(18, 14);

    generateWalls();
}

void WorldTanks::tick(float deltaTime)
{
    _getch();
    switch (_getch())
    {
    case 72:
        tank->move(ROTATION_Z_UP);
        break;
    case 75:
        tank->move(ROTATION_Z_LEFT);
        break;
    case 77:
        tank->move(ROTATION_Z_RIGHT);
        break;
    case 80:
        tank->move(ROTATION_Z_DOWN);
        break;
    default:
        tank->stopMove();
        break;
    }

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
                    Wall* w = createGameObject<Wall>();
                    w->setLocation(x1 + stepX * i, k + stepY * j);
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
                    Wall* w = createGameObject<Wall>();
                    w->setLocation(k + stepX * i, y1 + stepY * j);
                }
            }
        }
    }
}
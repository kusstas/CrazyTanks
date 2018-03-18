// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "WorldTanks.h"
#include "GameObject.h"
#include "Tank.h"

#include "Screen.h"
#include "Pixel.h"

#include <stdio.h>
#include <conio.h>

WorldTanks::WorldTanks()
{
    offsetWorld_ = DVector2D(1, 1);
    size_ = DVector2D(40, 15);
    tank = nullptr;
}

void WorldTanks::beginPlay()
{
    
    createGameObject()->setLocation(10, 10);
    tank = createGameObject<Tank>();
    createGameObject()->setLocation(2, 10);
    createGameObject()->setLocation(10, 2);
    
    tank->setLocation(18, 14);
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
// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#include "World.h"
#include "GameObject.h"

#include "Screen.h"
#include "Pixel.h"

#include <iterator>

using namespace std;

World::World()
{
}

World::World(const DVector2D& size)
{
    size_ = size;
}

World::World(int xSize, int ySize) : World(DVector2D(xSize, ySize))
{
}

World::~World()
{
    if (gameObjects.size() > 0)
    {
        vector<GameObject*>::iterator begin = gameObjects.begin();
        vector<GameObject*>::iterator end = gameObjects.end();

        for (vector<GameObject*>::iterator i = begin; i != end; ++i)
        {
            delete *i;
        }
    }
}

void World::beginPlay()
{
}

void World::tick(float deltaTime)
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        GameObject* go = gameObjects[i];

        if (go->isActive() && !go->isStatic())
            go->tick(deltaTime);
    }

    handleCollision();

    // phys tick
    for (int i = 0; i < gameObjects.size(); i++)
    {
        GameObject* go = gameObjects[i];

        if (go->isActive() && !go->isStatic())
            go->physTick();
    }

    // clear object
    for (vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end(); ++i)
    {
        GameObject* go = *i;
        if (go->isShouldBeDestroyed())
        {
            vector<GameObject*>::iterator t = i - 1;
            gameObjects.erase(i);
            i = t;
            delete go;
        }
    }
}

void World::draw(Screen& screen)
{
    if (gameObjects.size() > 0)
    {
        const vector<GameObject*>::iterator begin = gameObjects.begin();
        const vector<GameObject*>::iterator end = gameObjects.end();

        for (vector<GameObject*>::iterator i = begin; i != end; ++i)
        {
            GameObject* go = *i;

            if (go->isActive())
            {
                int x = go->getLocation().x + offsetWorld_.x;
                int y = go->getLocation().y + offsetWorld_.y;

                screen.draw(x, y, go->getDrawing());
            }
        }
    }
}

const DVector2D& World::getSize() const
{
    return size_;
}

const vector<GameObject*>& World::getGameObjects() const
{
    return gameObjects;
}

GameObject* World::getGameObjectFromLocation(DVector2D location)
{
    GameObject* go = nullptr;

    if (gameObjects.size() > 0)
    {
        vector<GameObject*>::iterator begin = gameObjects.begin();
        vector<GameObject*>::iterator end = gameObjects.end();

        for (vector<GameObject*>::iterator i = begin; i != end; ++i)
        {
            GameObject* curr = *i;
            if (location == curr->getLocation())
            {
                go = curr;
                break;
            }
        }
    }
    return go;
}

GameObject* World::getGameObjectFromLocation(int x, int y)
{
    return getGameObjectFromLocation(DVector2D(x, y));
}

GameObject* World::createGameObject()
{
    GameObject* go = createGameObject<GameObject>();
    return go;
}

void World::handleCollision()
{
    if (gameObjects.size() > 1)
    {
        vector<GameObject*>::iterator begin = gameObjects.begin();
        vector<GameObject*>::iterator end = gameObjects.end();

        for (vector<GameObject*>::iterator i = begin; i != end - 1; ++i)
        {
            GameObject* go1 = *i;

            for (vector<GameObject*>::iterator j = begin; j != end; ++j)
            {
                GameObject* go2 = *j;

                if (go1 == go2)
                    continue;

                DVector2D v1 = go1->getLocation() - go1->getPrevLocation();
                DVector2D v2 = go2->getLocation() - go2->getPrevLocation();

                bool block = go1->isBlockObject() && go2->isBlockObject();
                bool intersect = go1->getLocation() == go2->getLocation();

                if (v1 != DVector2D::zeroVector && v2 != DVector2D::zeroVector)
                {
                    intersect = intersect || go1->getLocation() == go2->getPrevLocation();
                }

                if (intersect)
                {
                    go1->onOverlap(*go2, go1->getLocation());
                    go2->onOverlap(*go1, go2->getLocation());

                    if (block)
                    {
                        go1->setLocation(go1->getPrevLocation());
                    }
                }
            }
        }
    }
}
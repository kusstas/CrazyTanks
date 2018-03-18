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
    if (gameObjects.size() > 0)
    {
        vector<GameObject*>::iterator begin = gameObjects.begin();
        vector<GameObject*>::iterator end = gameObjects.end();

        for (vector<GameObject*>::iterator i = begin; i != end; ++i)
        {
            GameObject* go = *i;

            if (go->isActive() && !go->isStatic())
                go->tick(deltaTime);
        }

        handleCollision();

        for (vector<GameObject*>::iterator i = begin; i != end; ++i)
        {
            GameObject* go = *i;

            if (go->isActive() && !go->isStatic())
                go->physTick();
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

void World::destroyGameObject(const GameObject& gameObject)
{
    vector<GameObject*>::iterator begin = gameObjects.begin();
    vector<GameObject*>::iterator end = gameObjects.end();

    for (vector<GameObject*>::iterator i = begin; i != end; ++i)
    {
        if (&gameObject == *i)
        {
            gameObjects.erase(i);
            break;
        }
    }

    delete &gameObject;
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

            for (vector<GameObject*>::iterator j = i + 1; j != end; ++j)
            {
                GameObject* go2 = *j;

                DVector2D dCurr = go1->getLocation() - go2->getLocation();
                DVector2D dPrev = go1->getPrevLocation() - go2->getPrevLocation();

                bool block = go1->isBlockObject() && go2->isBlockObject();
                bool intersect = (dCurr == DVector2D::zeroVector) || dCurr == (dPrev * -1.0f);

                if (intersect) 
                {
                    go1->onOverlap(*go2, go1->getLocation());
                    go2->onOverlap(*go1, go2->getLocation());

                    if (block)
                    {
                        if (go1->isMove())
                            go1->setLocation(go1->getPrevLocation());
                        if (go2->isMove())
                            go2->setLocation(go2->getPrevLocation());
                    }
                }
            }
        }
    }
}
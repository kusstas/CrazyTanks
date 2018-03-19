// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef WORLD_H
#define WORLD_H

#include "CoreMinimal.h"

#include <vector>
#include <type_traits>

using namespace std;

class GameObject;
class Screen;

class World
{

public:

    World();
    World(const DVector2D& size);
    World(int xSize, int ySize);
    virtual ~World();

    virtual void beginPlay();
    virtual void tick(float deltaTime);
    virtual void draw(Screen& screen);

    const DVector2D& getSize() const;
    const vector<GameObject*>& getGameObjects() const;

    GameObject* getGameObjectFromLocation(DVector2D location);
    GameObject* getGameObjectFromLocation(int x, int y);

    template <class T>
    T* createGameObject();
    GameObject* createGameObject();

protected:

    DVector2D size_;
    DVector2D offsetWorld_;

    vector<GameObject*> gameObjects;

private:

    void handleCollision();
    void destroyObjects();
};

template <class T>
T* World::createGameObject()
{
    // Only for compilation (throw error, if <T> non-inherited from GameObject)
    static_assert(std::is_base_of<GameObject, T>::value, "You can create only those classes that are inherited from GameObject");

    // Create object and add to vector
    T* go = new T(*this);
    gameObjects.push_back(go);

    go->beginPlay();
    return go;
}

#endif // !WORLD_H
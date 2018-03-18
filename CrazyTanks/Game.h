// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef GAME_H
#define GAME_H

#include "World.h"

#include <type_traits>

class Screen;

class Game
{
public:

    Game();
    virtual ~Game();

    virtual void beginPlay();
    virtual void tick(float deltaTime);
    virtual void draw(Screen& screen);

protected:

    template <class T>
    void loadWorld();

private:

    World* world;
};

template <class T>
void Game::loadWorld()
{
    // Only for compilation (throw error, if <T> non-inherited from World)
    static_assert(std::is_base_of<World, T>::value, "You can create only those classes that are inherited from World");

    if (world != nullptr)
        delete world;

    world = new T();
    world->beginPlay();
}

#endif // !GAME_H
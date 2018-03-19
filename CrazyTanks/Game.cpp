#include "Game.h"

Game::Game()
{
    world = nullptr;
}

Game::~Game()
{
    if (world != nullptr)
        delete world;
}

void Game::beginPlay()
{
}

void Game::tick(float deltaTime)
{
    if (world != nullptr)
        world->tick(deltaTime);
}

void Game::draw(Screen& screen)
{
    if (world != nullptr)
        world->draw(screen);
}
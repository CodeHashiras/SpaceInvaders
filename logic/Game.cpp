#include "Game.h"

Game::Game()
{
    this->initObjects();
}

void Game::initObjects()
{
    this->player = new Player(0, 0);
    this->initEnemies();
    this->initBlocks();
}

void Game::initEnemies()
{
    for (int i = 0; i < ENEMIES_PER_ROW; i++)
        for (int j = 0; j < ENEMIES_PER_COLUMN; j++)
        {
            // create and append an enemy object
        }
}

void Game::initBlocks()
{
}

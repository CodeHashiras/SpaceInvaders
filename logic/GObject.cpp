#include "GObject.h"

void GObject::reduceLife()
{
    this->lives--;
}

bool GObject::isAlive()
{
    return (this->lives > 0);
}

int GObject::getPosX()
{
    return this->posX;
}

int GObject::getPosY()
{
    return this->posY;
}

uint8_t GObject::getLives()
{
    return this->lives;
}

void GObject::setLives(const uint8_t lives)
{
    this->lives = lives;
}

void GObject::setPosition(const int x, const int y)
{
    this->posX = x;
    this->posY = y;
}

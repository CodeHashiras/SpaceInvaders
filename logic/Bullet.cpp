#include "Bullet.h"

void Bullet::move(const int dir)
{
    this->posY += (dir * this->speed);
}

Bullet::Bullet()
{
    this->lives = 0;
}

Bullet::Bullet(const int x, const int y)
{
    this->posX = x;
    this->posY = y;
    this->lives = MAX_BULLET_LIVES;
}

void Bullet::reset(const int x, const int y)
{
    this->lives = MAX_BULLET_LIVES;
    this->setPosition(x, y);
}

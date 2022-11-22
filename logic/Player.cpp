#include "Player.h"

void Player::move(const int dir)
{
    this->posX += (dir * this->speed);
}

void Player::shoot()
{
    if (!this->bullet->isAlive())
        this->bullet->reset(this->posX, this->posY);
}

Bullet *Player::getBullet()
{
    return this->bullet;
}

Player::Player(const int x, const int y)
{
    this->posX = x;
    this->posY = y;
    this->lives = MAX_PLAYER_LIVES;
    this->bullet = new Bullet();
}


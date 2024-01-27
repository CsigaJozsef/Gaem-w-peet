#include "../include/Player.hpp"

Player::Player() : _speed(5)
{
}

Player::~Player()
{
}

int Player::getX()
{
    return _pos.x;
}

int Player::getY()
{
    return _pos.y;
}

void Player::move(direction d, double delta)
{
    if (d == UP)
    {
        _pos.y -= std::ceil(_speed * delta);
    }

    if (d == DOWN)
    {
        _pos.y += std::ceil(_speed * delta);
    }

    if (d == LEFT)
    {
        _pos.x -= std::ceil(_speed * delta);
    }

    if (d == RIGHT)
    {
        _pos.x += std::ceil(_speed * delta);
    }

    // std::cout << _pos <<std::endl;
}
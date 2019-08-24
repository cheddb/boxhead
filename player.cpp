#include "player.h"

Player::Player() : Entity()
{
    life = 100;
}
Player::~Player()
{
    
}


void Player::frame()
{
//    int oldX = pos.x;
//    int oldY = pos.y;


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        pos.x --;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        pos.x ++;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        pos.y --;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        pos.y ++;
    }
    
}


void Player::draw()
{
    
}

bool Player::mustRemove() const
{
    return false;
}

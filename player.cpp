#include "player.h"

Player::Player() : Entity()
{
    life = 100;
    sprite = sprite(g_tex.getTexture(TextureManager::Character));
}
Player::~Player()
{

}


void Player::frame()
{
    int oldX = pos.x;
    int oldY = pos.y;
    float oldDir = dir;

    Vector2i pixelPos = sf::Mouse::getPosition(window);
    Vector2f worldPos = window.mapPixelToCoords(pixelPos);
    dir = atan( (worldPos.y - pos.y)/(worldPos.x - pos.x) );


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
  int s_pos_x = 0;
  int s_pos_y = 0;
  if(dir<-0.79 && dir>-2.35)
    s_pos_y = 0;
  else if(dir<0.79 && dir>-0.79)
    s_pos_y = 27;
  else if(dir<0.79 && dir<-2.35)
    s_pos_y = 54;
  else
    s_pos_y = 81;


  sprite.setPosition(float(pos.x), float(pos.y));

  sprite.setTextureRect( IntRect(s_pos_x, s_pos_y, 15, 27));
  g_window.draw(sprite);
}

bool Player::mustRemove() const
{
    return false;
}

#include "player.h"
#include "texturemanager.h"
#include "world.h"
#include "projectile.h"

Player::Player() : Entity()
{
    life = 100;
    sprite.setTexture(g_tex.getTexture(TextureManager::Character));
    sprite.setTextureRect(IntRect(0, 0, 16, 29));
}
Player::~Player()
{

}


void Player::frame()
{
    int oldX = pos.x;
    int oldY = pos.y;

    Vector2i m_pixelPos = sf::Mouse::getPosition(g_window);
    Vector2f m_worldPos = g_window.mapPixelToCoords(m_pixelPos);
    float delta_y = (m_worldPos.y - pos.y);
    float delta_x = (m_worldPos.x - pos.x);
    if(delta_y>abs(delta_x))
      anim_dir = 0;
    else if(delta_x>abs(delta_y))
      anim_dir = 33;
    else if(delta_y < -abs(delta_x))
      anim_dir = 64;
    else
      anim_dir = 97;


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
    if(!g_world.isFree(getRect(), this))
    {
      pos.x = oldX;
      pos.y = oldY;
    }

    if(anim_counter++ > 10){
        ++anim_step %= 4;
        if(oldX == pos.x && oldY == pos.y)
            anim_step = 0;
        anim_counter = 0;
    }

    if(Mouse::isButtonPressed(Mouse::Left))
    {
      Pos initial_pos;
      if(delta_y>abs(delta_x))
        initial_pos = Pos(pos.x, pos.y+15);
      else if(delta_x>abs(delta_y))
        initial_pos = Pos(pos.x+8, pos.y);
      else if(delta_y < -abs(delta_x))
        initial_pos = Pos(pos.x, pos.y-8);
      else
        initial_pos = Pos(pos.x-14, pos.y);

      Projectile* created = new Projectile(initial_pos);
      Pos objective = Pos(m_worldPos.x*10, m_worldPos.y*10);
      created->dir = ((objective-pos)*256)/(objective+pos).norm();
      g_world.addEntity(created);

    }

}


void Player::draw()
{
  int s_pos_x = anim_step*16;
  int s_pos_y = anim_dir;

  sprite.setPosition(float(pos.x-8), float(pos.y-15));

  sprite.setTextureRect( IntRect(s_pos_x, s_pos_y, 16, 29));
  g_window.draw(sprite);
}

bool Player::mustRemove() const
{
    return false;
}

IntRect Player::getRect() const{
    return IntRect(pos.x-8, pos.y-15, 16, 29);
}

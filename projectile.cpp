#include "projectile.h"

Projectile::Projectile() : Entity()
{
  life=100;
  speed=3; //TODO change in fct of projectile
  sprite.setTexture(g_tex.getTexture(TextureManager::Objects));
  sprite.setTextureRect(IntRect(231, 56, 1, 1));
}

Projectile::~Projectile()
{

}


void Projectile::frame()
{
  if(life==0)
    return;
  for(int i=0; i<speed;++i)
  {
    pos += dir;
    if(!g_world.areaEffect(IntRect(pos.x, pos.y, 1, 1), collision))
    {
      return;
    }
  }
  life-=1;
}


void Projectile::draw()
{
  if(life==0)
    return;

  sprite.setPosition(float(pos.x), float(pos.y));
  g_window.draw(sprite);
}

bool Projectile::mustRemove() const {
    return life==0;
}

void collision(Entity* e){
  if(!PROJECTILE)
  {
    e.life--;
    life=0;
  }
}

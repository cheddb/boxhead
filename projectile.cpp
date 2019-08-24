#include "projectile.h"
#include "texturemanager.h"
#include "world.h"

bool collision(Entity* e){
  if(e->getType() != Entity::Type_Projectile)
  {
    e->getDamages(1);
    return true;
  }
  return false;
}


Projectile::Projectile(Pos start) : Entity()
{
  pos = start;

  life=10;
  speed=2; //TODO change in fct of projectile
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
  for(int i=0; i<speed;i++)
  {
    pos += dir/32;
    if(g_world.areaEffect(IntRect(pos.x, pos.y, 1, 1), collision)>0)
    {
      life=0;
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

IntRect Projectile::getRect() const{
    return IntRect(pos.x, pos.y, 1, 1);
}

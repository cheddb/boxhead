#include "projectile.h"
#include "texturemanager.h"
#include "world.h"

bool collision(Entity* e){
  if(e->getType() == Entity::Type_Enemy)
  {
    return true;
  }
  return false;
}
bool doDamages(Entity* e){
  if(e->getType() == Entity::Type_Enemy)
  {
    e->getDamages(100);
    return true;
  }
  return false;
}


Projectile::Projectile(Pos start, Player::Weapon origin) : Entity()
{
    pos = start;

    life=25;
    speed=2; //TODO change in fct of projectile
    sprite.setTexture(g_tex.getTexture(TextureManager::Objects));
    sprite.setTextureRect(IntRect(231, 56, 1, 1));

    switch (origin) {
        case Player::Shotgun:
            damages = 100;
            impact = Precision;
            radius = 1;
            break;
        case Player::Grenade:
            damages = 100;
            impact = Explosive;
            radius = 10;
            break;
        case Player::Carrot:
            damages = 1;
            impact = Precision;
            radius = 1;
            break;
        default:
            damages = 1;
            impact = Precision;
            radius = 1;
            break;
    }
}

Projectile::~Projectile()
{

}


void Projectile::frame()
{

    for(int i=0; i<speed;i++)
    {
        pos += dir;
        if(g_world.areaEffect(IntRect(pos.x, pos.y, 1, 1), collision)>0)
        {
            g_world.areaEffect(IntRect(pos.x-radius, pos.y-radius, radius*2, radius*2), doDamages);
            life=0;
            return;
        }
    }
    life-=1;
}


void Projectile::draw(){

    sprite.setPosition(float(pos.x), float(pos.y));
    g_window.draw(sprite);

}

bool Projectile::mustRemove() const {
    return life<=0;
}

IntRect Projectile::getRect() const{
    return IntRect(pos.x, pos.y, 1, 1);
}

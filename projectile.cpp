#include "projectile.h"
#include "texturemanager.h"
#include "world.h"

bool collision(Entity* e){
  if(e->getType() != Entity::Type_Player )
  {
    return true;
  }
  return false;
}
bool doDamages(Entity* e, const void* data){
    // if(e->getType() == Entity::Type_Enemy)
    // {
        explosion exp = *(explosion*) data;
        if(exp.impact == Projectile::Precision)
            e->getDamages(exp.damages);
        else
        {
            Pos p_pos = e->getPos();
            int dist = sqrt( (exp.x-p_pos.x)*(exp.x-p_pos.x) + (exp.y-p_pos.y)*(exp.y-p_pos.y) );
            if(exp.radius >= dist)
                e->getDamages( exp.damages*dist/exp.radius );
        }
        return true;
    // }
    // return false;
}


Projectile::Projectile(Pos start, Player::Weapon origin) : Entity()
{
    pos = start;

    life=25;
    speed=2; //TODO change in fct of projectile
    sprite.setTexture(g_tex.getTexture(TextureManager::Objects));
    sprite.setTextureRect(IntRect(231,56,1,1));

    explosion_step = 0;
    switch (origin) {
        case Player::Shotgun:
            exp.damages = 50;
            exp.impact = Precision;
            exp.radius = 1;
            break;
        case Player::Grenade:
            exp.damages = 40;
            exp.impact = Explosive;
            exp.radius = 100;
            break;
        case Player::Carrot:
            exp.damages = 1;
            exp.impact = Precision;
            exp.radius = 1;
            break;
        default:
            exp.damages = 1;
            exp.impact = Precision;
            exp.radius = 1;
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
            explode();
            return;
        }
    }
    life-=1;
    if(life==0)
        explode();

}


void Projectile::draw()
{

    // if(explosion_step <=7*8)
    // {
        sprite.setPosition(float(pos.x), float(pos.y));
        // sprite.setTextureRect(listExp[explosion_step/8]);
        g_window.draw(sprite);
        // explosion_step+= explosion_step>0?1:0;
    // }

}

bool Projectile::mustRemove() const {
    return life<=0;
}

IntRect Projectile::getRect() const{
    return IntRect(pos.x, pos.y, 1, 1);
}

void Projectile::explode(){
    explosion_step = 8;
    exp.x = pos.x;
    exp.y = pos.y;
    g_world.areaEffect(IntRect(pos.x-exp.radius, pos.y-exp.radius, exp.radius*2, exp.radius*2), doDamages, static_cast<void*>(&exp));
    life=0;
}

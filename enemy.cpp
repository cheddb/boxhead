#include "enemy.h"
#include "texturemanager.h"
#include "world.h"

Enemy::Enemy(Pos start) : Entity()
{
    pos = start;
    sprite.setTexture(g_tex.getTexture(TextureManager::Log));
    sprite.setTextureRect(IntRect(0, 0, 32, 32));
    life = 30;
    dev_speed = Pos(0,0);
}
Enemy::~Enemy(){

}


void Enemy::frame(){
    IntRect r, rx, ry, rRND;
    r = getRect();
    rx = getRect();
    ry = getRect();
    rRND = getRect();

    Player* p = g_world.getPlayer();

    Pos dir = p->getPos()-pos;
    dir *= 2.f / dir.norm(); // speed of 5

    r.top += dir.y + dev_speed.y;
    r.left += dir.x + dev_speed.x;
    ry.top += dir.y + dev_speed.y;
    rx.left += dir.x + dev_speed.x;
    rRND.top += dev_speed.y*0.2;
    rRND.left += dev_speed.x*0.2;


    dev_speed *= 0.8;
    if(abs(dir.y)<abs(dir.x))
    {
        dev_speed.y+= ((rand() % 3)-1);
        dev_speed.y = std::min(dev_speed.y, 3.f);
        dev_speed.y = std::max(dev_speed.y, -3.f);
    }
    else
    {
        dev_speed.x+= ((rand() % 3)-1);
        dev_speed.x = std::min(dev_speed.x, 3.f);
        dev_speed.x = std::max(dev_speed.x, -3.f);
    }

    if(g_world.isFree(r, this)){
        pos.x = r.left+16;
        pos.y = r.top+16;
    }
    else if(g_world.isFree(rx, this)){
        dev_speed.x = pos.x-rx.left+16;
        pos.x = rx.left+16;
        pos.y = rx.top+16;
    }
    else if(g_world.isFree(ry, this)){
        dev_speed.x = pos.y-ry.left+16;
        pos.x = ry.left+16;
        pos.y = ry.top+16;
    }
    else if(g_world.isFree(rRND, this)){
        pos.x = rRND.left+16;
        pos.y = rRND.top+16;
    }

}

IntRect Enemy::getRect() const{
    return IntRect(pos.x-16, pos.y-16, 32, 32);
}


void Enemy::draw(){
    sprite.setPosition(getRect().left, getRect().top);
    g_window.draw(sprite);
}

bool Enemy::mustRemove() const{
    return life<=0;
}

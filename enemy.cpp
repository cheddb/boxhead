#include "enemy.h"
#include "texturemanager.h"
#include "world.h"

Enemy::Enemy(Pos start) : Entity()
{
    pos = start;
    sprite.setTexture(g_tex.getTexture(TextureManager::Log));
    sprite.setTextureRect(IntRect(0, 0, 32, 32));
}
Enemy::~Enemy(){

}


void Enemy::frame(){
    IntRect r;
    r = getRect();
    r.top += rand() %3 - 1;
    r.left += rand() %3 - 1;

    if(g_world.isFree(r, this)){
        pos.x = r.left+16;
        pos.y = r.top+16;
    }

}

IntRect Enemy::getRect() const{
    return IntRect(pos.x-16, pos.y-16, 32, 32);
}


void Enemy::draw(){
    sprite.setPosition(pos.x, pos.y);
    g_window.draw(sprite);
}

bool Enemy::mustRemove() const{
    return life<=0;
}

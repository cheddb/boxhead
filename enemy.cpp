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
    pos.x += rand()%3 - 1;
    pos.y += rand()%3 - 1;


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

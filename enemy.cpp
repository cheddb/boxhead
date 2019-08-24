#include "enemy.h"
#include "texturemanager.h"

Enemy::Enemy(Pos start) : Entity()
{
    pos = start;
    sprite.setTexture(g_tex.getTexture(TextureManager::Log));
    sprite.setTextureRect(IntRect(0, 0, 32, 32));
}
Enemy::~Enemy(){

}


void Enemy::frame(){
    pos.x += rand()%2;
}


void Enemy::draw(){
    sprite.setPosition(pos.x, pos.y);
    g_window.draw(sprite);
}

bool Enemy::mustRemove() const{
    return life<=0;
}

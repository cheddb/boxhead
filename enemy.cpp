#include "enemy.h"
#include "texturemanager.h"

Enemy::Enemy(Pos start) : Entity()
{
    pos = start;
    sprite.setTexture(g_tex.getTexture(TextureManager::Log));
}
Enemy::~Enemy(){

}


void Enemy::frame(){
    pos.x += rand()%2;
}


void Enemy::draw(){
    
}

bool Enemy::mustRemove() const{
    return life<=0;
}

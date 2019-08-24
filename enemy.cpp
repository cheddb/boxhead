#include "enemy.h"
#include "texturemanager.h"
#include "world.h"

Enemy::Enemy(Pos start) : Entity()
{
    pos = start;
    sprite.setTexture(g_tex.getTexture(TextureManager::Log));
    sprite.setTextureRect(IntRect(0, 0, 32, 32));
    life = 30;
}
Enemy::~Enemy(){

}


void Enemy::frame(){
    IntRect r;
    r = getRect();

    Player* p = g_world.getPlayer();

    Pos dir = p->getPos()-pos;
    dir *= 2.f / dir.norm(); // speed of 5

    r.top += dir.y;
    r.left += dir.x;

    if(g_world.isFree(r, this)){
        pos.x = r.left+16;
        pos.y = r.top+16;
    }

}

IntRect Enemy::getRect() const{
    return IntRect(pos.x-16, pos.y-16, 32, 32);
}


void Enemy::draw(){
    sprite.setPosition(getRect().left, getRect().top);
    g_window.draw(sprite);


    if(life!=30){//print life bar
        //background
        RectangleShape rect;
        rect.setSize(sf::Vector2f(32, 3));
        rect.setOutlineColor(sf::Color::Green);
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineThickness(1.f);
        rect.setPosition(getRect().left, getRect().top-5);
        g_window.draw(rect);


        rect.setSize(sf::Vector2f(32*life/30, 3));
        rect.setFillColor(sf::Color::Green);
        rect.setOutlineThickness(0.f);
        g_window.draw(rect);
    }
}

bool Enemy::mustRemove() const{
    return life<=0;
}

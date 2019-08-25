#include "enemy.h"
#include "texturemanager.h"
#include "world.h"

bool attack(Entity* e){
  if(e->getType() == Entity::Type_Player)
  {
    e->getDamages(1);
    return true;
  }
  return false;
}

Enemy::Enemy(Pos start) : Entity()
{
    pos = start;
    sprite.setTexture(g_tex.getTexture(TextureManager::Log));
    sprite.setTextureRect(IntRect(0, 0, 32, 32));
    life = 30;
    move=0;
}
Enemy::~Enemy(){

}


void Enemy::frame(){
    if(move > 0){
        move--;
        return;
    }

    Player* p = g_world.getPlayer();
    float distToPlayer = Pos(p->getPos()-pos).norm();
    Pos force = Pos(p->getPos()-pos).normalize()*10;
    for(Entity **it = g_world.firstEntity(); it != g_world.lastEntity(); it++){
        if((*it)->getType() == Type_Item) continue;

        Pos delta = (*it)->getPos() - pos;
        force += -std::min(100*distToPlayer, 10000.f)*delta.normalize() / std::max(delta.normSquare(), 0.001f);
    }

    pos += force.normalize();

    if(p->getRect().intersects(getRect())){// attack the player !!!!
        p->getDamages(1);
        p->setImpact(Pos(p->getPos() - pos).normalize()*3.f);
        move = 60;// 1 second of pause

    }

//    if(!p->getRect())
//        pos = old;

//    if(move == 0)
//    {
//        IntRect r, rx, ry;
//        r = getRect();
//        rx = getRect();
//        ry = getRect();

//        Player* p = g_world.getPlayer();

//        Pos dir = p->getPos()-pos;
//        dir *= 2.f / dir.norm(); // speed of 5

//        r.top += dir.y;
//        r.left += dir.x;
//        ry.top += dir.y+1;
//        rx.left += dir.x+1;

//        if(g_world.isFree(r, this)){
//            pos.x = r.left+16;
//            pos.y = r.top+16;
//        }
//        else
//        {
//            g_world.areaEffect(r, attack);
//            if(g_world.isFree(rx, this)){
//            pos.x = rx.left+16;
//            pos.y = rx.top+16;
//            }
//            else if(g_world.isFree(ry, this)){
//                pos.x = ry.left+16;
//                pos.y = ry.top+16;
//            }
//        }
//        move=3;
//    }
//    else
//        move--;
}

IntRect Enemy::getRect() const{
    return IntRect(int(pos.x)-16, int(pos.y)-16, 32, 32);
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

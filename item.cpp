#include "item.h"
#include "texturemanager.h"
#include "world.h"

Item::Item() : Entity(){
    pos.x = rand() % 500;
    pos.y = rand() % 500;
    sprite.setTexture(g_tex.getTexture(TextureManager::Objects));
    sprite.setTextureRect(IntRect(0,0,16,16));
    life = 1;
}

bool Item::mustRemove() const{return life <= 0;}

void Item::draw() {
    sprite.setPosition(pos.x, pos.y);
    g_window.draw(sprite);
}
void Item::frame(){
    //check for a collision with a player. if so, have him reload, and remove the box
    if(g_world.areaEffect(getRect(), [](Entity* e) {
        if(e->getType() == Entity::Type_Player){
            dynamic_cast<Player *>(e)->reload();
            return true;
        }
        return false;
    }))
        life = 0;
}
Entity::Type Item::getType() const {return Type_Item;}


IntRect Item::getRect() const {
    return IntRect(pos.x-8, pos.y-8, 16, 16);

}


#include "spawn.h"

#include "enemy.h"
#include "world.h"
#include "texturemanager.h"

Spawn::Spawn() : Entity()
{
    pos.x = 50;
    pos.y = 0;
    frameSinceLastSpawn = 0;
    spawnRate = 60;

    sprite.setTexture(g_tex.getTexture(TextureManager::Objects));
    sprite.setTextureRect(IntRect(416, 0, 32, 32));

}
Spawn::~Spawn()
{

}

void Spawn::frame()
{
    if(frameSinceLastSpawn%spawnRate==0){
        Enemy* created = new Enemy(pos + Pos(35, 0));

        if(g_world.isFree(created->getRect(), nullptr))
            g_world.addEntity(created);
        else
            delete created;
    }
    frameSinceLastSpawn++;
}


void Spawn::draw(){
    sprite.setPosition(pos.x, pos.y);
    g_window.draw(sprite);

}

bool Spawn::mustRemove() const {
    return false;
}

IntRect Spawn::getRect() const{
    return IntRect(pos.x-16, pos.y-16, 32, 32);
}

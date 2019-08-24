#include "spawn.h"

#include "enemy.h"
#include "world.h"

#include <iostream>

Spawn::Spawn() : Entity()
{
    pos.x = 50;
    pos.y = 0;
    frameSinceLastSpawn = 0;
    spawnRate = 100;
}
Spawn::~Spawn()
{

}

void Spawn::frame()
{
    if(frameSinceLastSpawn%spawnRate==0){
        Enemy* created = new Enemy(pos + Pos(30, 0));

        if(g_world.isFree(created->getRect(), nullptr))
            g_world.addEntity(created);
        else
            delete created;
    }
    frameSinceLastSpawn++;
}


void Spawn::draw()
{

}

bool Spawn::mustRemove() const {
    return false;
}

IntRect Spawn::getRect() const{
    return IntRect(pos.x, pos.y, 0, 0);
}

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
    frameSinceLastSpawn++;
    if(frameSinceLastSpawn%spawnRate==0)
    {
        Enemy* created = new Enemy(pos);
        g_world.addEntity(created);
    }
}


void Spawn::draw()
{

}

bool Spawn::mustRemove() const {
    return false;
}

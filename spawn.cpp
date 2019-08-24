#include "spawn.h"

#include "enemy.h"
#include "world.h"

#include <iostream>

Spawn::Spawn()
{
    pos.x = 50;
    pos.y = 0;
    frameSinceLastSpawn = 0;
    spawnRate = 1000;
}
Spawn::~Spawn()
{

}

void Spawn::frame()
{
    frameSinceLastSpawn++;
    if(frameSinceLastSpawn>spawnRate)
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

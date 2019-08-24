#include "world.h"

#include "player.h"
#include "spawn.h"

#include <iostream>


World::World()
{
    player = new Player();
    entities[0] = player;
    entities[1] = new Spawn();
    nbEntities = 2;
}

World::~World()
{
    for(int i = 0;i<nbEntities;i++)
    {
        delete entities[i];
    }
}

Player* World::getPlayer()
{
    return player;
}

void World::frame()
{
    for(int i = 0;i<nbEntities;i++)
    {
        entities[i]->frame();
    }
}

void World::draw()
{
    for(int i = 0;i<nbEntities;i++)
    {
        entities[i]->draw();
    }
}

void World::addEntity(Entity *e)
{
    if(nbEntities>=max_entities)return;
    entities[nbEntities] = e;
    nbEntities ++;
}

void World::cleanEntities()
{
    for(int i = 0;i<nbEntities;i++)
    {
        if(entities[i]->mustRemove())
        {
            nbEntities--;
            delete entities[i];
            entities[i] = entities[nbEntities];
            i--;
        }
    }
}
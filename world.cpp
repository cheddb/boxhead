#include "world.h"

#include "player.h"
World::World()
{
    entities[0] = new Player();
    nbEntities = 1;
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
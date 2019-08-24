#include "world.h"

World::World()
{
    entities[0] = new Player();
    nbEntities = 1;
}


World::frame()
{
    for(int i = 0;i<nbEntities;i++)
    {
        entities[i]->frame();
    }
}

World::draw()
{
    for(int i = 0;i<nbEntities;i++)
    {
        entities[i]->draw();
    }
}

World::addEntity(Entity *e)
{
    entities[nbEntities] = e;
    nbEntities ++;
}

World::cleanEntities()
{
    for(int i = 0;i<nbEntities;i++)
    {
        if(entities[i]->mustRemove())
        {
            nbEntities--;
            entities[i] = entities[nbEntities];
            i--;
        }
    }
}
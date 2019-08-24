#include "world.h"

World::World()
{

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
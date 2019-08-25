#include "world.h"

#include "player.h"
#include "spawn.h"

#include "item.h"

World::World()
{
    srand(time(nullptr));
    player = new Player();
    entities[0] = player;
    entities[1] = new Spawn();
    nbEntities = 2;
}

World::~World(){
    for(int i = 0;i<nbEntities;i++)
    {
        delete entities[i];
    }
}

Player* World::getPlayer()
{
    return player;
}

bool World::isFree(const IntRect &r, Entity *exeption) const
{
    for(int i = 0; i < nbEntities; i++){
        if(entities[i] == exeption || entities[i]->getType()==Entity::Type_Item) continue;

        if(entities[i]->getRect().intersects(r))
            return false;
    }

    return true;
}

std::vector<Player *> World::collision(const IntRect &r) const{
    assert(false);
}

int World::areaEffect(const IntRect &r, EntityCallback callback){
    int ans = 0;
    for(int i = 0; i < nbEntities; i++){
        if(entities[i]->getRect().intersects(r))
            ans += callback(entities[i]);
    }
    return ans;
}
int World::areaEffect(const IntRect &r, EntityGenericCallback callback, const void *data){
    int ans = 0;
    for(int i = 0; i < nbEntities; i++){
        if(entities[i]->getRect().intersects(r))
            ans += callback(entities[i], data);
    }
    return ans;
}


void World::frame()
{
    //add some chests
    if(rand() % 180 == 0)
        addEntity(new Item());


    for(int i = 0;i<nbEntities;i++)
    {
        entities[i]->frame();
    }
    cleanEntities();
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

#ifndef SPAWN_H
#define SPAWN_H

#include "entity.h"


class Spawn : public Entity 
{
public:
    Spawn();
    ~Spawn();
    virtual bool mustRemove() const;

    virtual void draw();
    virtual void frame();
    
    IntRect getRect() const;

    Type getType() const{return Type_Spawner;}

private:
    
    int frameSinceLastSpawn;
    int spawnRate;
};

#endif // SPAWN_H

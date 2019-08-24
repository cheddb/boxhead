#ifndef WORLD_H
#define WORLD_H

#include "entity.h"

class World{
public:
    World();

    void addEntity(Entity *e);
    void draw();
    void frame();


private:
    static const int max_entities = 500;
    Entity *entities[max_entities];
    int nbEntities = 0;

    /// rm the entities flagged 'mustRemove'
    void cleanEntities();
};

#endif // WORLD_H

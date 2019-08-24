#ifndef WORLD_H
#define WORLD_H

#include "entity.h"
#include "player.h"

class World{
public:
    World();
    ~World();


    void addEntity(Entity *e);
    void draw();
    void frame();
    Player* getPlayer();

    /// true if the given rect is intersecting with nothing. The entity 'exeption' is not checked
    bool isFree(IntRect const& r, Entity *exeption=nullptr) const;

    /// return a list of colliding entities with the given rect
    std::vector<Player *> collision(IntRect const& r) const;


    /// applies the callback to every entity in the given rect. return nb of true the callback returned
    int areaEffect(IntRect const& r, EntityCallback callback);
private:
    static const int max_entities = 500;
    Entity *entities[max_entities];
    int nbEntities = 0;

    /// rm the entities flagged 'mustRemove'
    void cleanEntities();
    Player* player;
};

#endif // WORLD_H

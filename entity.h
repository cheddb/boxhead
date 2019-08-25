#ifndef ENTITY_H
#define ENTITY_H

#include "includes.h"

class Entity{
public:
    Entity();

    virtual ~Entity();

    virtual bool mustRemove() const=0;

    virtual void draw() = 0;
    virtual void frame() = 0;
    void getDamages(int damages);

    enum Type{
        Type_Enemy, Type_Projectile, Type_Player, Type_Tower, Type_Spawner, Type_Item
    };

    virtual Type getType() const = 0;

    inline Pos getPos() const{return pos;}

    virtual IntRect getRect() const = 0;
protected:
    int life;
    Pos pos;

    Sprite sprite;
};

#endif // ENTITY_H

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
protected:
    int life;
    Pos pos;

};

#endif // ENTITY_H

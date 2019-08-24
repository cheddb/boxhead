#ifndef TOWER_H
#define TOWER_H

#include "entity.h"


class Tower : public Entity
{
public:
    Tower();
    ~Tower();
    virtual bool mustRemove() const;

    virtual void draw();
    virtual void frame();

    Type getType() const{return Type_Tower;}
};

#endif // TOWER_H

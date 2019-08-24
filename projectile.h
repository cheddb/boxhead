#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"

class Projectile : public Entity
{
public:
    Projectile();
    virtual bool mustRemove() const;

    virtual void draw();
    virtual void frame();
};

#endif // PROJECTILE_H

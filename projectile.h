#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"

class Projectile : public Entity
{
public:
    Projectile();
    ~Projectile();

    virtual bool mustRemove() const;

    virtual void draw();
    virtual void frame();

    Pos dir;
    int speed;
};

#endif // PROJECTILE_H

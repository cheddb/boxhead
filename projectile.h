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

    Type getType() const{return Type_Projectile;}

};

#endif // PROJECTILE_H

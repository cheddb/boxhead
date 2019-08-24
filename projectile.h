#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"

class Projectile : public Entity
{
public:
    Projectile(Pos start);
    ~Projectile();

    bool mustRemove() const;

    void draw();
    void frame();
    IntRect getRect() const;

    Pos dir;
    int speed;
    Type getType() const{return Type_Projectile;}
};

#endif // PROJECTILE_H

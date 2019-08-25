#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"
#include "player.h"

class Projectile : public Entity
{
public:
    Projectile(Pos start, Player::Weapon origin);
    ~Projectile();

    bool mustRemove() const;

    void draw();
    void frame();
    IntRect getRect() const;


    Pos dir;
    int speed;
    Type getType() const{return Type_Projectile;}
protected:
    enum Type {Explosive, Precision, NbType};

    int damages;
    int impact;
    int radius;
};

#endif // PROJECTILE_H

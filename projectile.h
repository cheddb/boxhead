#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"
#include "player.h"

typedef struct
{
    int x;
    int y;
    int radius;
    int damages;
    int impact;
} explosion;

const IntRect listExp[] = {
    IntRect(215, 56, 1, 1),
    IntRect(66, 66, 30, 30),
    IntRect(97, 66, 30, 30),
    IntRect(129, 66, 30, 30),
    IntRect(162, 66, 30, 30),
    IntRect(193, 66, 30, 30),
    IntRect(224, 66, 30, 30),
    IntRect(258, 66, 30, 30)
};
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

    enum Type {Explosive, Precision, NbType};

protected:

    explosion exp;
    void explode();
    int explosion_step;
};

#endif // PROJECTILE_H

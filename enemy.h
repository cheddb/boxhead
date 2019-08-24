#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy : public Entity{
public:
    Enemy(Pos start);
    ~Enemy();

    bool mustRemove() const;

    void draw();
    void frame();

    IntRect getRect() const;

    Type getType() const{return Type_Enemy;}
protected:
    int move;
};

#endif // ENEMY_H

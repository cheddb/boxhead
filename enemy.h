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
};

#endif // ENEMY_H

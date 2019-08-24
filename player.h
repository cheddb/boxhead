#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include <math.h>

class Player : public Entity{
public:
    Player();
    ~Player();
    bool mustRemove() const;

    int anim_step;
    int anim_dir;

    void draw();
    void frame();

    IntRect getRect() const;

};

#endif // PLAYER_H

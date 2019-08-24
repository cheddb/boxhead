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
    int anim_counter;

    void draw();
    void frame();
};

#endif // PLAYER_H

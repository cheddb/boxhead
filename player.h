#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity{
public:
    Player();
    bool mustRemove() const;

    void draw();
    void frame();
};

#endif // PLAYER_H

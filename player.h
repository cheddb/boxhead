#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity{
public:
    Player();
    ~Player();
    bool mustRemove() const;

    void draw();
    void frame();

    IntRect getRect() const;

};

#endif // PLAYER_H

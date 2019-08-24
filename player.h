#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity{
public:
    Player();
    virtual bool mustRemove();

    virtual void draw();
    virtual void frame();
};

#endif // PLAYER_H

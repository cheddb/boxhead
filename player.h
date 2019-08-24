#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include <math.h>
#include <SFML/Audio/Sound.hpp>

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

    IntRect getRect() const;

    Type getType() const{return Type_Player;}

private:
    SoundBuffer shotgunSound;
    sf::Sound sound;

};

#endif // PLAYER_H

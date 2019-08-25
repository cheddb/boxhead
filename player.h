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

    enum Weapon{
        Shotgun, Grenade, Carrot,
        NbWeapon
    };

    /// reload completely a random weapon
    void reload();
private:
    SoundBuffer shotgunSound, dryGunSound;
    sf::Sound sound;


    /// nb of munitions per weapon
    int amo[NbWeapon] = {0};
    int weapon = Shotgun;


    void shoot(Pos viewDir);
};

#endif // PLAYER_H

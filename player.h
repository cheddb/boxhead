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

    /// reload completely a random weapon
    void reload();
private:
    SoundBuffer shotgunSound, dryGunSound;
    sf::Sound sound;


    enum Weapon{
        Shotgun, Grenade,
        NbWeapon
    };

    /// nb of ammunition per weapon
    int amo[NbWeapon] = {0};
    Weapon weapon = Shotgun;


    void shoot(Pos viewDir);
};

#endif // PLAYER_H

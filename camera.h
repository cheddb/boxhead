#ifndef CAMERA_H
#define CAMERA_H

#include "includes.h"

class Camera{
public:
    Camera();

    void draw(sf::Sprite s, Pos p);
private:
    Pos offset;
};

#endif // CAMERA_H

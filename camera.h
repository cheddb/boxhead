#ifndef CAMERA_H
#define CAMERA_H

#include "includes.h"

class Camera{
public:
    Camera();

    void draw(sf::Sprite const& s, Pos p);
private:
    Pos offset;
};

extern Camera g_cam;

#endif // CAMERA_H

#ifndef INCLUDES_H
#define INCLUDES_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <cassert>
#include <iostream>


struct Pos{
    int x,  y;
    Pos(int X=0,int Y=0){x=X;y=Y;}

    Pos operator+(Pos const& other) const{return Pos(x+other.x, y+other.y);}
    Pos operator-(Pos const& other) const{return Pos(x-other.x, y-other.y);}

    Pos& operator+=(Pos const& other){x += other.x; y+=other.y;return *this;}

    float norm() const{return sqrtf(float(x)*x+float(y)*y);}

    Pos operator*(float k) const{return Pos(int(x*k),int(y*k));}
    Pos& operator*=(float k) {x *=k; y*=k;return *this;}
    Pos operator/(float k) const{return Pos(int(x/k),int(y/k));}
};
struct Rect{
    int x,  y, w, h;
};

using namespace sf;

class World;
class Entity;

typedef bool (*EntityCallback)(Entity*);

extern World g_world;

extern RenderWindow g_window;

#endif // INCLUDES_H

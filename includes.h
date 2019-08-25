#ifndef INCLUDES_H
#define INCLUDES_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <cassert>
#include <iostream>


struct Pos{
    float x,  y;
    Pos(float X=0,float Y=0){x=X;y=Y;}

    Pos operator+(Pos const& other) const{return Pos(x+other.x, y+other.y);}
    Pos operator-(Pos const& other) const{return Pos(x-other.x, y-other.y);}

    Pos& operator+=(Pos const& other){x += other.x; y+=other.y;return *this;}

    float norm() const{return sqrtf(float(x)*x+float(y)*y);}
    Pos normalize() const{return (*this)/norm();}

    Pos operator*(float k) const{return Pos(x*k,y*k);}
    Pos& operator*=(float k) {x *=k; y*=k;return *this;}
    Pos operator/(float k) const{return Pos(x/k,y/k);}
};
struct Rect{
    int x,  y, w, h;
};

using namespace sf;

class World;
class Entity;

typedef bool (*EntityCallback)(Entity*);
typedef bool (*EntityGenericCallback)(Entity*, const void*);

extern World g_world;

extern RenderWindow g_window;

extern Font g_font;

#endif // INCLUDES_H

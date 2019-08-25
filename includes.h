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

    friend Pos operator+(Pos const& a, Pos const& b) {return Pos(a.x+b.x, a.y+b.y);}
    friend Pos operator-(Pos const& a, Pos const& b) {return Pos(a.x-b.x, a.y-b.y);}

    inline Pos& operator+=(Pos const& other){x += other.x; y+=other.y;return *this;}

    inline float norm() const{return sqrtf(float(x)*x+float(y)*y);}
    inline float normSquare() const{return x*x+y*y;}
    Pos normalize() const{return (*this)/std::max(norm(), 0.001f);}

    friend Pos operator*(float k, Pos const& p) {return Pos(p.x*k,p.y*k);}
    friend Pos operator*(Pos const& p,float k) {return Pos(p.x*k,p.y*k);}
    inline Pos& operator*=(float k) {x *=k; y*=k;return *this;}
    inline Pos operator/(float k) const{return Pos(x/k,y/k);}
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

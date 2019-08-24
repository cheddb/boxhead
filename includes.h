#ifndef INCLUDES_H
#define INCLUDES_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

struct Pos{
    int x,  y;
    Pos(int X=0,int Y=0){x=X;y=Y;}

    Pos operator+(Pos const& other) const{return Pos(x+other.x, y+other.y);}
};
struct Rect{
    int x,  y, w, h;
};

using namespace sf;

class World;

extern World g_world;

extern RenderWindow g_window;

#endif // INCLUDES_H

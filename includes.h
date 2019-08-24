#ifndef INCLUDES_H
#define INCLUDES_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

struct Pos{
    int x,  y;
};
struct Rect{
    int x,  y, w, h;
};

using namespace sf;

class World;

extern World g_world;

#endif // INCLUDES_H

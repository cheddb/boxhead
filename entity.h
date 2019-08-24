#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

struct Pos{
    int x,  y;
};

class Entity{
public:
    Entity();

    virtual ~Entity();

    virtual bool mustRemove() const=0;

    void draw();
protected:
    int life;
    Pos pos;

};

#endif // ENTITY_H

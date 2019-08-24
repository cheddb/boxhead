#ifndef ITEM_H
#define ITEM_H

#include "entity.h"

/**
 * @brief The Item class represent a stack of items on the floor
 */
class Item : public Entity{
public:
    Item();
    virtual bool mustRemove() const;

    virtual void draw() ;
    virtual void frame();
    virtual Type getType() const ;


    virtual IntRect getRect() const ;
private:

};

#endif // ITEM_H

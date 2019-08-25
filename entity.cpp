#include "entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::getDamages(int damages)
{
	life-= damages;
}

void Entity::setPos(const Pos &value)
{
    pos = value;
}

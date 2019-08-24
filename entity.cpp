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

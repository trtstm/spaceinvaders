#include <iostream>

#include "Livable.hpp"

#include "messages/DiedMessage.hpp"

Livable::Livable(int entity, int health)
	: Component(LIVABLE, entity), health(health)
{
}

Livable::~Livable()
{
}

void Livable::doDamage(int damage)
{
	health -= damage;

	if(health <= 0) {
		DiedMessage msg(entity);
		notifyObservers(msg);
	}
}

int Livable::getHealth() const
{
	return health;
}

#include <iostream>

#include "Livable.hpp"

#include "messages/DiedMessage.hpp"

Livable::Livable(int health)
	: Component(LIVABLE), health(health)
{
}

Livable::~Livable()
{
}

void Livable::doDamage(int damage)
{
	health -= damage;

	if(health <= 0) {
		DiedMessage msg(0);
		notifyObservers(msg);
	}
}

int Livable::getHealth() const
{
	return health;
}

#include <iostream>

#include "Livable.hpp"

#include "messages/DiedMessage.hpp"

Livable::Livable(std::shared_ptr<Entity> entity, int health)
	: Component(LIVABLE, entity), health(health)
{
}

Livable::~Livable()
{
}

void Livable::doDamage(int damage)
{
	health -= damage;
	std::cout << health << std::endl;
	if(health <= 0) {
		DiedMessage msg(getEntity());
		notifyObservers(msg);
	}
}

int Livable::getHealth() const
{
	return health;
}

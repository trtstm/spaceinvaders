#include <memory>

#include "Alien.hpp"

#include "components/AlienMovable.hpp"
#include "components/Collidable.hpp"
#include "components/Livable.hpp"

Alien::Alien(Coordinate location)
	: Entity(), 
		movable(id, location), 
		collidable(id, sf::Rect<double>(0.0, 0.0, 16.0, 16.0)),
		livable(id, 1)
{
}

Alien::~Alien()
{
}

Movable& Alien::getMovable()
{
	return movable;
}

Collidable& Alien::getCollidable()
{
	return collidable;
}

Livable& Alien::getLivable()
{
	return livable;
}

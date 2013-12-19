#include <memory>

#include "Spaceship.hpp"

#include "components/SpaceshipMovable.hpp"
#include "components/Collidable.hpp"
#include "components/Livable.hpp"

Spaceship::Spaceship(Coordinate location, double speed)
	: Entity(), 
		movable(id, location, speed), 
		collidable(id, sf::Rect<double>(0.0, 0.0, 26.0, 15.0)),
		livable(id, 1)
{
}

Spaceship::~Spaceship()
{
}

Movable& Spaceship::getMovable()
{
	return movable;
}

Collidable& Spaceship::getCollidable()
{
	return collidable;
}

Livable& Spaceship::getLivable()
{
	return livable;
}

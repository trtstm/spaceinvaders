#include <memory>

#include "Spaceship.hpp"

#include "components/SpaceshipMovable.hpp"
#include "components/Collidable.hpp"
#include "components/Livable.hpp"

Spaceship::Spaceship(Coordinate location, double speed)
	: Entity(std::make_shared<SpaceshipMovable>(idCounter, location, speed),
			std::make_shared<Collidable>(idCounter, sf::Rect<double>(0.0, 0.0, 26.0, 15.0)),
			std::make_shared<Livable>(idCounter, 1))
{
}

Spaceship::~Spaceship()
{
	std::cout << "Deleted spaceship" << std::endl;
}

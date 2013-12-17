#include <memory>

#include "Alien.hpp"

#include "components/AlienMovable.hpp"
#include "components/Collidable.hpp"
#include "components/Livable.hpp"

Alien::Alien(Coordinate location)
	: Entity(std::make_shared<AlienMovable>(idCounter, location),
			std::make_shared<Collidable>(idCounter, sf::Rect<double>(0.0, 0.0, 50.0, 30.0)),
			std::make_shared<Livable>(idCounter, 1))
{
}

Alien::~Alien()
{
	std::cout << "Deleted alien" << std::endl;
}

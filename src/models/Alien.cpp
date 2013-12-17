#include <memory>

#include "Alien.hpp"

#include "components/AlienMovable.hpp"

Alien::Alien(Coordinate location)
	: Entity(std::make_shared<AlienMovable>(idCounter, location))
{
}

Alien::~Alien()
{
	std::cout << "Deleted alien" << std::endl;
}

#include <memory>

#include "LaserCannon.hpp"

LaserCannon::LaserCannon(Coordinate position)
	: Entity(1, position, 400, sf::Rect<double>(0.0, 0.0, 26.0, 15.0))
{
}

LaserCannon::~LaserCannon()
{
}

#include "Bunker.hpp"

Bunker::Bunker(Coordinate position)
	: Entity(BUNKER, 1, position, 0, sf::Rect<double>(0.0, 0.0, 42.0, 32.0))
{
}

Bunker::~Bunker()
{
}

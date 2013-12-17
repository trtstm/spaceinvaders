#include "AlienMovable.hpp"

#include "messages/MoveMessage.hpp"

AlienMovable::AlienMovable(int entity, Coordinate location)
	: Movable(entity, location, 0.0)
{
}


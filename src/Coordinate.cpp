#include "Coordinate.hpp"

std::ostream& operator<<(std::ostream& out, const Coordinate& coordinate)
{
	out << "(" << coordinate.x << "," << coordinate.y << ")";

	return out;
}


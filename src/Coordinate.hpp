#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include <iostream>

struct Coordinate {
	Coordinate(double x, double y)
		: x(x), y(y)
	{
	}

	double x;
	double y;

	friend std::ostream& operator<<(std::ostream& out, const Coordinate& coordinate);
};

#endif

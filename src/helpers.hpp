#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <string>
#include <sstream>

template <class T>
std::string toString(const T& value)
{
	std::ostringstream ss;
	ss << value;

	return ss.str();
}


#endif

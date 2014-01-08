#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <string>
#include <sstream>

/**
* Convert a type to a string.
*
* @param value The value that has to be converted.
* @return The string representation.
*/
template <class T>
std::string toString(const T& value)
{
	std::ostringstream ss;
	ss << value;

	return ss.str();
}


#endif

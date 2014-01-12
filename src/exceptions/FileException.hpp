#ifndef FILE_EXCEPTION_HPP
#define FILE_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class FileException : public std::exception
{
	public:
		FileException(const std::string& file) : file(file) {}

		virtual const char* what() const throw()
		{
			return ("Could not load file " + file).c_str();
		}

	private:
		std::string file;
};

#endif

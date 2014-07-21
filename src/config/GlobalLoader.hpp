#ifndef GLOBAL_LOADER_H
#define GLOBAL_LOADER_H

#include <string>

#include "ConfigLoader.hpp"

class GlobalLoader : public ConfigLoader {
	public:
		bool load(std::string);

		int getResolutionX() const;
		int getResolutionY() const;

		int getFps() const;

		int getPlayers() const;
};

#endif

#ifndef GLOBAL_LOADER_H
#define GLOBAL_LOADER_H

#include <string>
#include <map>

#include "ConfigLoader.hpp"

class GlobalLoader : public ConfigLoader {
	public:
		bool load(std::string);

		int getResolutionX() const;
		int getResolutionY() const;

		int getFps() const;

		int getPlayers() const;

		std::map<std::string, std::string> getGraphics() const;
		std::map<std::string, std::string> getFonts() const;
};

#endif

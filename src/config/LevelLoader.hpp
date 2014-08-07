#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H

#include <string>
#include <vector>

#include "ConfigLoader.hpp"

class LevelLoader : public ConfigLoader {
	public:
		bool load(std::string);

		int getWidth() const;
		int getHeight() const;
		double getSpeed() const;
		std::vector<std::vector<int>> getEnemies() const;
	private:
		int width;
		int height;
		double speed;
		std::vector<std::vector<int>> enemies;
};

#endif

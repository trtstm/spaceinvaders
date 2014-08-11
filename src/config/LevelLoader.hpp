#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H

#include <string>
#include <vector>

#include "ConfigLoader.hpp"

class LevelLoader : public ConfigLoader {
	public:
		/*
		* See base class.
		*/
		bool load(std::string);

		/*
		* Get width of the level.
		*
		* @return The width.
		*/
		int getWidth() const;

		/*
		* Get height of the level.
		*
		* @return The height.
		*/
		int getHeight() const;

		/*
		* Get speed multiplier of the level.
		*
		* @return The speed multiplier.
		*/
		double getSpeed() const;

		/*
		* Get the invaders in the level.
		*
		* @return The invaders.
		*/
		std::vector<std::vector<int>> getEnemies() const;
	private:
		int width;
		int height;
		double speed;
		std::vector<std::vector<int>> enemies;
};

#endif

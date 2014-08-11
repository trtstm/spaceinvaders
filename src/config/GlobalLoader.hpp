#ifndef GLOBAL_LOADER_H
#define GLOBAL_LOADER_H

#include <string>
#include <map>
#include <vector>

#include "ConfigLoader.hpp"
#include "LevelLoader.hpp"

class GlobalLoader : public ConfigLoader {
	public:
		/**
		* See base class.
		*/
		bool load(std::string);

		/**
		* Get x resolution.
		*
		* @return The x resolution.
		*/
		int getResolutionX() const;

		/**
		* Get y resolution.
		*
		* @return The y resolution.
		*/
		int getResolutionY() const;

		/**
		* Get fps.
		*
		* @return The fps.
		*/
		int getFps() const;

		/**
		* Get the graphics.
		*
		* @return The graphics.
		*/
		std::map<std::string, std::string> getGraphics() const;

		/**
		* Get the fonts.
		*
		* @return The fonts.
		*/
		std::map<std::string, std::string> getFonts() const;

		/**
		* Get the levels.
		*
		* @return The levels.
		*/
		std::vector<LevelLoader> getLevels() const;

	private:
		std::vector<LevelLoader> levels;
};

#endif

#ifndef HIGHSCORE_LOADER_H
#define HIGHSCORE_LOADER_H

#include <string>
#include <vector>

#include "ConfigLoader.hpp"

struct Highscore {
	int score;
	int players;
};

class HighscoreLoader : public ConfigLoader {
	public:

		/**
		* See base class.
		*/
		bool load(std::string);

		/**
		* Get the highscores.
		*
		* @return The highscores.
		*/
		std::vector<Highscore> getHighscores() const;

		/**
		* Add a highscore.
		*
		* @param score The score.
		* @param players The number of players.
		*/
		void addHighscore(int score, int players);

		/**
		* Save the highscore to disk.
		*/
		void save();

	private:
		std::string file;

};

#endif

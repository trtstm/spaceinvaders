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
		bool load(std::string);


		std::vector<Highscore> getHighscores() const;

		void addHighscore(int score, int players);

		void save();

	private:
		std::string file;

};

#endif

#ifndef SCORE_VIEW_HPP
#define SCORE_VIEW_HPP

#include <SFML/Graphics.hpp>

#include "Resources.hpp"

namespace View {

class ScoreView {
	public:
		ScoreView(const Resources& resources);

		void render(sf::RenderWindow& w, const Resources& resources, int score);

	private:
		sf::Text text;
};

}

#endif

#ifndef SCORE_VIEW_HPP
#define SCORE_VIEW_HPP

#include <SFML/Graphics.hpp>

#include "Resources.hpp"

namespace View {

class ScoreView {
	public:
		/**
		* @param resources The resources to load from.
		*/
		ScoreView(const Resources& resources);

		/**
		* Do the rendering.
		*
		* @param w The window to render to.
		* @param resources The resources to load from.
		* @param score The score.
		*/
		void render(sf::RenderWindow& w, const Resources& resources, int score);

	private:
		sf::Text text;
};

}

#endif

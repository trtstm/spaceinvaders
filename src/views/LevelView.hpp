#ifndef LEVEL_VIEW_HPP
#define LEVEL_VIEW_HPP

#include <SFML/Graphics.hpp>

#include "Resources.hpp"

class LevelView {
	public:
		LevelView(const Resources& resources);

		void render(sf::RenderWindow& w, const Resources& resources, unsigned int level);

	private:
		sf::Text text;
};

#endif

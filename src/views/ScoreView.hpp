#ifndef SCORE_VIEW_HPP
#define SCORE_VIEW_HPP

#include <SFML/Graphics.hpp>

#include "helpers.hpp"
#include "Resources.hpp"

class ScoreView {
	public:

	void render(sf::RenderWindow& w, Resources& resources, int score)
	{
		sf::Text text;
		text.setFont(resources.fonts["default"]);
		text.setString(toString(score));
		text.setCharacterSize(16);
		text.setColor(sf::Color::Red);
		text.setPosition(600.0, 10.0);
		w.draw(text);
	}

	private:
		sf::Text text;
};

#endif

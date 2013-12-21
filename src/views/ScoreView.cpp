#include "ScoreView.hpp"

#include "helpers.hpp"

ScoreView::ScoreView(const Resources& resources)
{
	text.setFont(resources.fonts.at("default"));
	text.setCharacterSize(16);
	text.setColor(sf::Color::Red);
	text.setPosition(600.0, 10.0);
}

void ScoreView::render(sf::RenderWindow& w, const Resources& resources, int score)
{
	text.setString(toString(score));
	w.draw(text);
}


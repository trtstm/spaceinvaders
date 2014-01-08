#include "LevelView.hpp"

#include "helpers.hpp"

namespace View {

LevelView::LevelView(const Resources& resources)
{
	text.setFont(resources.fonts.at("default"));
	text.setCharacterSize(16);
	text.setColor(sf::Color::Red);
	text.setPosition(600.0, 50.0);
}

void LevelView::render(sf::RenderWindow& w, const Resources& resources, unsigned int level)
{
	(void)resources;

	text.setString(toString(level));
	w.draw(text);
}

}

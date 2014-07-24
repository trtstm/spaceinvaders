#include "LevelView.hpp"

#include "helpers.hpp"

namespace View {

LevelView::LevelView(const Resources& resources, GlobalLoader globalConfig)
	: globalConfig(globalConfig)
{
	text.setFont(resources.fonts.at("default"));
	text.setCharacterSize(16);
	text.setColor(sf::Color::Red);
	text.setPosition(globalConfig.getResolutionX() - 200, 50.0);
}

void LevelView::render(sf::RenderWindow& w, const Resources& resources, unsigned int level)
{
	(void)resources;

	text.setString("Level: " + toString(level));
	w.draw(text);
}

}

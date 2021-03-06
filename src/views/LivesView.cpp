#include "LivesView.hpp"

#include "helpers.hpp"

namespace View {

LivesView::LivesView(const Resources& resources, GlobalLoader globalConfig)
	: globalConfig(globalConfig)
{
	text.setFont(resources.fonts.at("default"));
	text.setCharacterSize(16);
	text.setColor(sf::Color::Red);
	text.setPosition(globalConfig.getResolutionX() - 200, 90);
}

void LivesView::render(sf::RenderWindow& w, const Resources& resources, int lives)
{
	(void)resources;

	text.setString("Lives: " + toString(lives));
	w.draw(text);
}

}

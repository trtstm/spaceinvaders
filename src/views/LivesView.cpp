#include "LivesView.hpp"

#include "helpers.hpp"

namespace View {

LivesView::LivesView(const Resources& resources)
{
	text.setFont(resources.fonts.at("default"));
	text.setCharacterSize(16);
	text.setColor(sf::Color::Red);
	text.setPosition(600.0, 90);
}

void LivesView::render(sf::RenderWindow& w, const Resources& resources, int lives)
{
	(void)resources;

	text.setString("Lives: " + toString(lives));
	w.draw(text);
}

}

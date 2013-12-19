#ifndef SPACESHIP_GUI_VIEW_HPP
#define SPACESHIP_GUI_VIEW_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "GuiView.hpp"
#include "Observer.hpp"

#include "Coordinate.hpp"
#include "messages/Message.hpp"

#include "Resources.hpp"

class SpaceshipGuiView: public GuiView, public Observer {
	public:
		SpaceshipGuiView() {}
		SpaceshipGuiView(Coordinate position);

		bool notify(Message& msg);

		void render(sf::RenderWindow& w, const Resources& resources, double dt);

	private:
		sf::Sprite img;
};

#endif

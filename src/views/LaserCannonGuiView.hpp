#ifndef LASER_CANNON_GUI_VIEW_HPP
#define LASER_CANNON_GUI_VIEW_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "GuiView.hpp"
#include "Observer.hpp"

#include "Coordinate.hpp"
#include "messages/Message.hpp"

#include "Resources.hpp"

class LaserCannonGuiView : public GuiView, public Observer {
	public:
		LaserCannonGuiView(Coordinate position, const Resources& resources);

		bool notify(Message& msg);

		void render(sf::RenderWindow& w, const Resources& resources, double dt);

	private:
		sf::Sprite img;
};

#endif

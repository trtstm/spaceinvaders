#ifndef SPACESHIP_GUI_VIEW_HPP
#define SPACESHIP_GUI_VIEW_HPP

#include "GuiView.hpp"
#include "Observer.hpp"

#include "Coordinate.hpp"
#include "messages/Message.hpp"

#include "Resources.hpp"

namespace View {

class SpaceshipGuiView : public GuiView, public Observer {
	public:
		SpaceshipGuiView(Coordinate position, const Resources& resources);

		bool notify(Message::Message& msg);

		void render(sf::RenderWindow& w, const Resources& resources);

	private:
		sf::Sprite img;
};

}

#endif

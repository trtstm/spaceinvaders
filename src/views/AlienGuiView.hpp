#ifndef ALIEN_GUI_VIEW_HPP
#define ALIEN_GUI_VIEW_HPP

#include "GuiView.hpp"
#include "Observer.hpp"

#include "Coordinate.hpp"
#include "messages/Message.hpp"

#include "Resources.hpp"

class AlienGuiView : public GuiView, public Observer {
	public:
		AlienGuiView(Coordinate position, const Resources& resources);

		bool notify(Message& msg);

		void render(sf::RenderWindow& w, const Resources& resources, double dt);

	private:
		std::string curTexture;
		double timer;

		sf::Sprite img;

};

#endif

#ifndef BUNKER_LEFT_GUI_VIEW_HPP
#define BUNKER_LEFT_GUI_VIEW_HPP

#include <string>

#include "GuiView.hpp"
#include "Observer.hpp"

#include "Coordinate.hpp"
#include "messages/Message.hpp"

#include "Resources.hpp"

class BunkerLeftGuiView : public GuiView, public Observer {
	public:
		BunkerLeftGuiView(Coordinate position, const Resources& resources);

		bool notify(Message& msg);

		void render(sf::RenderWindow& w, const Resources& resources, double dt);

	private:
		sf::Sprite img1;
		sf::Sprite img2;
		sf::Sprite img3;

		int curImage;

		double timer;
};

#endif

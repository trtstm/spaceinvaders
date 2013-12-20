#ifndef BUNKER_GUI_VIEW_HPP
#define BUNKER_GUI_VIEW_HPP

#include <string>

#include "GuiView.hpp"
#include "Observer.hpp"

#include "Coordinate.hpp"
#include "messages/Message.hpp"

#include "Resources.hpp"

struct ImgInfo {
	std::string texture;
	sf::Sprite img;
};

class BunkerGuiView : public GuiView, public Observer {
	public:
		BunkerGuiView(Coordinate position);

		bool notify(Message& msg);

		void render(sf::RenderWindow& w, const Resources& resources, double dt);

	private:
		ImgInfo sprite1;
		ImgInfo sprite2;
		ImgInfo sprite3;

		double timer;
};

#endif

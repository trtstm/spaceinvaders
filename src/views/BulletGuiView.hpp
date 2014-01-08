#ifndef BULLET_GUI_VIEW_HPP
#define BULLET_GUI_VIEW_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "GuiView.hpp"
#include "Observer.hpp"

#include "Coordinate.hpp"
#include "messages/Message.hpp"

namespace View {

class BulletGuiView : public GuiView, public Observer {
	public:
		BulletGuiView(Coordinate position = Coordinate(0,0));

		bool notify(Message::Message& msg);

		void render(sf::RenderWindow& w);

	private:
};

}

#endif

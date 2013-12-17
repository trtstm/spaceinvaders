#ifndef ALIEN_GUI_VIEW_HPP
#define ALIEN_GUI_VIEW_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "Observer.hpp"
#include "messages/Message.hpp"
#include "models/Alien.hpp"

class AlienGuiView: public Observer {
	public:
		AlienGuiView(std::shared_ptr<Alien> alien);

		bool notify(Message& msg);

		void render(sf::RenderWindow& w);

	private:
		std::shared_ptr<Alien> alien;
};

#endif

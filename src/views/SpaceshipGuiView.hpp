#ifndef SPACESHIP_GUI_VIEW_HPP
#define SPACESHIP_GUI_VIEW_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "Observer.hpp"
#include "messages/Message.hpp"
#include "models/Spaceship.hpp"

class SpaceshipGuiView: public Observer {
	public:
		SpaceshipGuiView(std::shared_ptr<Spaceship> spaceship);

		bool notify(Message& msg);

		void render(sf::RenderWindow& w);

	private:
		std::shared_ptr<Spaceship> spaceship;
};

#endif

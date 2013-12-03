#ifndef BULLET_GUI_VIEW_HPP
#define BULLET_GUI_VIEW_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "Observer.hpp"
#include "messages/Message.hpp"
#include "models/Bullet.hpp"

class BulletGuiView : public Observer {
	public:
		BulletGuiView(std::shared_ptr<Bullet> bullet);

		bool notify(Message& msg);

		void render(sf::RenderWindow& w);

	private:
		std::shared_ptr<Bullet> bullet;
};

#endif

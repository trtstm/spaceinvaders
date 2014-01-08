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
		/**
		* @param position The initial position.
		*/
		BulletGuiView(Coordinate position = Coordinate(0,0));

		/**
		* Notify the view.
		*
		* @param msg The message.
		* @return False if the subject should remove us from the observer list, else true.
		*/
		bool notify(Message::Message& msg);

		/**
		* Do the rendering.
		*
		* @param w The window to render to.
		*/
		void render(sf::RenderWindow& w);

	private:
};

}

#endif

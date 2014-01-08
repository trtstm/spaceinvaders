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
		/**
		* @param position The initial position.
		* @param resources The resources to load from.
		*/
		SpaceshipGuiView(Coordinate position, const Resources& resources);

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
		* @param resources The resources to load from.
		*/
		void render(sf::RenderWindow& w, const Resources& resources);

	private:
		sf::Sprite img;
};

}

#endif

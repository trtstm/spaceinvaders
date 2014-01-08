#ifndef BUNKER_LEFT_GUI_VIEW_HPP
#define BUNKER_LEFT_GUI_VIEW_HPP

#include <string>

#include "GuiView.hpp"
#include "Observer.hpp"

#include "Coordinate.hpp"
#include "messages/Message.hpp"

#include "Resources.hpp"

namespace View {

class BunkerLeftGuiView : public GuiView, public Observer {
	public:
		/**
		* @param position The initial position.
		* @param resources The resources to load from.
		*/
		BunkerLeftGuiView(Coordinate position, const Resources& resources);

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
		* @param dt The delta time.
		*/
		void render(sf::RenderWindow& w, const Resources& resources, double dt);

	private:
		sf::Sprite img1;
		sf::Sprite img2;
		sf::Sprite img3;

		int curImage;

		double timer;
};

}

#endif

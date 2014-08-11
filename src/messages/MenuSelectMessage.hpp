#ifndef MENU_SELECT_MESSAGE_HPP
#define MENU_SELECT_MESSAGE_HPP

#include <memory>

#include "Message.hpp"

namespace Message {

class MenuSelectMessage : public Message {
	public:
		/**
		* @param selection The index of the menu button that was clicked.
		*/
		MenuSelectMessage(int selection);

		int selection;
};

}

#endif

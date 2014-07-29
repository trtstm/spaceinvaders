#ifndef MENU_SELECT_MESSAGE_HPP
#define MENU_SELECT_MESSAGE_HPP

#include <memory>

#include "Message.hpp"

namespace Message {

class MenuSelectMessage : public Message {
	public:
		MenuSelectMessage(int selection);

		int selection;
};

}

#endif

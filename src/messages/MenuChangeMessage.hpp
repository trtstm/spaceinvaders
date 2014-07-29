#ifndef MENU_CHANGE_MESSAGE_HPP
#define MENU_CHANGE_MESSAGE_HPP

#include <vector>
#include <string>

#include "Message.hpp"

namespace Message {

class MenuChangeMessage : public Message {
	public:
		MenuChangeMessage(std::vector<std::string> items);

		std::vector<std::string> items;
};

}

#endif

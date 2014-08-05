#ifndef MENU_CHANGE_MESSAGE_HPP
#define MENU_CHANGE_MESSAGE_HPP

#include <vector>
#include <string>

#include "Message.hpp"

#include "controllers/MenuController.hpp"

namespace Message {

class MenuChangeMessage : public Message {
	public:
		MenuChangeMessage(std::vector<std::string> items, Controller::MenuController::Menu menu);

		std::vector<std::string> items;

		Controller::MenuController::Menu menu;
};

}

#endif

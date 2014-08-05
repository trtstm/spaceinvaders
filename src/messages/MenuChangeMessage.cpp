#include "MenuChangeMessage.hpp"

namespace Message {

MenuChangeMessage::MenuChangeMessage(std::vector<std::string> items, Controller::MenuController::Menu menu)
	: Message(MENU_CHANGE, 0), items(items), menu(menu)
{
}

}

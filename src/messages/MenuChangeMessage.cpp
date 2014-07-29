#include "MenuChangeMessage.hpp"

namespace Message {

MenuChangeMessage::MenuChangeMessage(std::vector<std::string> items)
	: Message(MENU_CHANGE, 0), items(items)
{
}

}

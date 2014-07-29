#include "MenuSelectMessage.hpp"

namespace Message {

MenuSelectMessage::MenuSelectMessage(int selection)
	: Message(MENU_SELECT, 0), selection(selection)
{
}

}

#include <iostream>

#include "SpaceshipTextView.hpp"

#include "messages/MoveMessage.hpp"

bool SpaceshipTextView::notify(Message& msg)
{
	switch(msg.type) {
		case MOVE:
		{
			std::cout << "Spaceship new location: " << static_cast<MoveMessage&>(msg).newPosition << std::endl;	

			break;
		}
	};

	return true;
}

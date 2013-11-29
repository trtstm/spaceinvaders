#include <iostream>

#include "SpaceshipTextView.hpp"

#include "MoveMessage.hpp"

bool SpaceshipTextView::notify(Message& msg)
{
	switch(msg.getType()) {
		case MOVE:
		{
			std::cout << "Spaceship new location: " << static_cast<MoveMessage&>(msg).newPosition << std::endl;	

			break;
		}
	};

	return true;
}

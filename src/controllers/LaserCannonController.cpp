#include "LaserCannonController.hpp"

#include "messages/DiedMessage.hpp"
#include "messages/BulletHitMessage.hpp"

namespace Controller {

LaserCannonController::LaserCannonController(Model::LaserCannon* laserCannon, Input input)
	: laserCannon(laserCannon)
{
	if(input == ARROWS) {
		left = sf::Keyboard::Key::Left;
		right = sf::Keyboard::Key::Right;
	}else if(input == WASD) {
		left = sf::Keyboard::Key::A;
		right = sf::Keyboard::Key::D;
	}
}

void LaserCannonController::update(double dt)
{
 	if(sf::Keyboard::isKeyPressed(left)) {
		laserCannon->moveLeft(dt);
	}

 	if(sf::Keyboard::isKeyPressed(right)) {
		laserCannon->moveRight(dt);
	}
}

}

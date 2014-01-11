#include "LaserCannonController.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "messages/DiedMessage.hpp"
#include "messages/BulletHitMessage.hpp"

namespace Controller {

LaserCannonController::LaserCannonController(Model::LaserCannon* laserCannon)
	: laserCannon(laserCannon)
{
}

void LaserCannonController::update(double dt)
{
 	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		laserCannon->moveLeft(dt);
	}

 	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		laserCannon->moveRight(dt);
	}
}

}

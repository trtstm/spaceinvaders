#include "LaserCannonController.hpp"
#include "SpaceInvaders.hpp"

#include "messages/DiedMessage.hpp"
#include "messages/BulletHitMessage.hpp"

namespace Controller {

LaserCannonController::LaserCannonController(Model::LaserCannon* laserCannon, Input input, SpaceInvaders* game)
	: laserCannon(laserCannon), game(game)
{
	if(input == ARROWS) {
		left = sf::Keyboard::Key::Left;
		right = sf::Keyboard::Key::Right;
		shoot = sf::Keyboard::Key::Space;
	} else if(input == WASD) {
		left = sf::Keyboard::Key::A;
		right = sf::Keyboard::Key::D;
		shoot = sf::Keyboard::Key::S;
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

 	if(sf::Keyboard::isKeyPressed(shoot)) {
		this->game->shoot(this->laserCannon.get());
	}
}

}

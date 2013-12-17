#ifndef COLLIDABLE_HPP
#define COLLIDABLE_HPP

#include <memory>
#include <SFML/Graphics/Rect.hpp>

#include "Component.hpp"
#include "Coordinate.hpp"

class Collidable : public Component {
	public:
		Collidable(int entity, sf::Rect<double> rect);
		virtual ~Collidable();

		virtual void onCollision(int subject);

		bool hasCollided() const;

		sf::Rect<double> getRect() const;

	protected:
		sf::Rect<double> rect;

		bool collided;
};

#endif

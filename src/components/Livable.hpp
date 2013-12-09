#ifndef LIVABLE_HPP
#define LIVABLE_HPP

#include <memory>

#include "Component.hpp"
#include "models/Entity.hpp"

class Livable : public Component {
	public:
		Livable(std::shared_ptr<Entity> entity, int health);
		virtual ~Livable();		

		void doDamage(int damage);
		int getHealth() const;

	protected:
		int health;
};

#endif

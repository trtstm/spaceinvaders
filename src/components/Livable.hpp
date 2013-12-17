#ifndef LIVABLE_HPP
#define LIVABLE_HPP

#include <memory>

#include "Component.hpp"

class Livable : public Component {
	public:
		Livable(int entity, int health);
		virtual ~Livable();		

		void doDamage(int damage);
		int getHealth() const;

	protected:
		int health;
};

#endif

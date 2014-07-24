#ifndef LEVEL_VIEW_HPP
#define LEVEL_VIEW_HPP

#include <SFML/Graphics.hpp>

#include "Resources.hpp"
#include "config/GlobalLoader.hpp"

namespace View {

class LevelView {
	public:
		/**
		* @param resources The resources to load from.
		*/
		LevelView(const Resources& resources, GlobalLoader globalConfig);

		/**
		* Do the rendering.
		*
		* @param w The window to render to.
		* @param resources The resources to load from.
		* @param level The level.
		*/
		void render(sf::RenderWindow& w, const Resources& resources, unsigned int level);

	private:
		sf::Text text;
		GlobalLoader globalConfig;
};

}

#endif

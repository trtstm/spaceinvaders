#ifndef LIVES_VIEW_HPP
#define LIVES_VIEW_HPP

#include <SFML/Graphics.hpp>

#include "Resources.hpp"
#include "config/GlobalLoader.hpp"

namespace View {

class LivesView {
	public:
		/**
		* @param resources The resources to load from.
		*/
		LivesView(const Resources& resources, GlobalLoader globalConfig);

		/**
		* Do the rendering.
		*
		* @param w The window to render to.
		* @param resources The resources to load from.
		* @param lives The lives.
		*/
		void render(sf::RenderWindow& w, const Resources& resources, int lives);

	private:
		sf::Text text;
		GlobalLoader globalConfig;
};

}

#endif

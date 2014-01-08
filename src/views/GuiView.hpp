#ifndef GUI_VIEW_HPP
#define GUI_VIEW_HPP

#include <SFML/Graphics.hpp>

namespace View {

class GuiView {
	public:
		GuiView() {}
		GuiView(sf::RectangleShape sprite);
		virtual ~GuiView();

	protected:
		sf::RectangleShape sprite;
		
};

}

#endif

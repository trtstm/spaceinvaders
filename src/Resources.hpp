#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <string>
#include <map>
#include <SFML/Graphics.hpp>

struct Resources {
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;

};

#endif

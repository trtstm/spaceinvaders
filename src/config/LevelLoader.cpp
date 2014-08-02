#include "LevelLoader.hpp"

#include <iostream>

bool LevelLoader::load(std::string file)
{
	ConfigLoader::load(file);

	int width = 0;
	int height = 0;

	std::vector<std::vector<int>> enemies;

	bool first = true;
	for(const auto& kv1 : this->pt.get_child("enemies")) {
		int i = 0;

		enemies.push_back(std::vector<int>());
		for(const auto& kv2 : kv1.second.get_child("")) {
			if(first) {
				width++;
			}
			i++;

			try {
				int monster = kv2.second.get<int>("");
				if(monster < 0 || monster > 1) {
					std::cerr << "Invalid level, " << monster << " is an invalid number." << std::endl;
					return false;
				}

				enemies.back().push_back(monster);	

			} catch(boost::property_tree::ptree_bad_path& err) {
				std::cerr << "Invalid level, could not find enemies." << std::endl;
				return false;
			} catch(boost::property_tree::ptree_bad_data& err) {
				std::cerr << "Invalid level, only integers are allowed." << std::endl;
				return false;
			}
		}
		if(!first && i != width) {
			std::cerr << "Invalid level, all rows should be of same size." << std::endl;
			return false;
		}

		height++;

		first = false;
	}

	this->width = width;
	this->height = height;
	this->enemies = enemies;

	return true;
}

int LevelLoader::getWidth() const
{
	return width;
}

int LevelLoader::getHeight() const
{
	return height;
}

std::vector<std::vector<int>> LevelLoader::getEnemies() const
{
	return enemies;
}

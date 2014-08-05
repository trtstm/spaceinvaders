#include "HighscoreLoader.hpp"

#include <iostream>

bool HighscoreLoader::load(std::string file)
{
	this->file = file;

	ConfigLoader::load(file);

	try {
		this->pt.get_child("scores");
	} catch(boost::property_tree::ptree_bad_path& err) {
		std::cerr << "Invalid highscore file, could not find scores." << std::endl;
		this->pt.put_child("scores", boost::property_tree::ptree());
		return false;
	}

	for(const auto& kv : this->pt.get_child("scores")) {
		try {
			int score = kv.second.get<int>("score");
			int players = kv.second.get<int>("players");

		} catch(boost::property_tree::ptree_bad_path& err) {
			std::cerr << "Invalid highscore file, could not find score or players." << std::endl;
			this->pt.get_child("scores").clear();
			return false;
		} catch(boost::property_tree::ptree_bad_data& err) {
			std::cerr << "Invalid highscore file, score and players should be integers." << std::endl;
			this->pt.get_child("scores").clear();
			return false;
		}

	}

	return true;
}

std::vector<Highscore> HighscoreLoader::getHighscores() const
{
	std::vector<Highscore> scores;

	try {
		this->pt.get_child("scores");
	} catch(boost::property_tree::ptree_bad_path& err) {
		std::cerr << "Could not get highscores." << std::endl;
		return scores;
	}

	for(const auto& kv : this->pt.get_child("scores")) {
		try {
			int score = kv.second.get<int>("score");
			int players = kv.second.get<int>("players");

			scores.push_back(Highscore{score, players});

		} catch(boost::property_tree::ptree_bad_path& err) {
			std::cerr << "Could not get score/players." << std::endl;
			return scores;
		} catch(boost::property_tree::ptree_bad_data& err) {
			std::cerr << "Could not get score/players. Invalid type." << std::endl;
			return scores;
		}

	}

	return scores;
}

void HighscoreLoader::addHighscore(int score, int players)
{
	boost::property_tree::ptree treeNew;

	boost::property_tree::ptree treeRoot;
	boost::property_tree::ptree treeScore;
	boost::property_tree::ptree treePlayers;

	treeRoot.put("score", score);
	treeRoot.put("players", players);

	bool inserted = false;
	for(const auto& kv : this->pt.get_child("scores")) {
		if(score > kv.second.get<int>("score") && !inserted) {
			treeNew.push_back(std::make_pair("", treeRoot));
			inserted = true;
		}

		treeNew.push_back(std::make_pair("", kv.second));
	}

	if(!inserted) {
		treeNew.push_back(std::make_pair("", treeRoot));
	}

	pt.clear();
	pt.put_child("scores", treeNew);


}

void HighscoreLoader::save()
{
	try {
		boost::property_tree::write_json(file, pt);
	} catch(boost::property_tree::json_parser::json_parser_error e) {
		std::cerr << "Could not save highscores: " << e.message() << std::endl;
	}
}

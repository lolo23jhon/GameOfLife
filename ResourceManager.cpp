#include "main.h"

std::unordered_map<std::string, sf::Font> ResourceManager::s_fonts{};


void ResourceManager::loadFont(const std::string& t_fontFilename) {

	std::string fontName{ t_fontFilename };
	fontName.pop_back(); // f
	fontName.pop_back(); // t
	fontName.pop_back(); // t
	fontName.pop_back(); // .

	s_fonts.emplace(fontName, sf::Font());

	s_fonts.at(fontName).loadFromFile(t_fontFilename);
}

const sf::Font& ResourceManager::getFont(const std::string& t_fontName){
	return s_fonts.at(t_fontName);
}

void ResourceManager::releaseResources() { s_fonts.clear(); }

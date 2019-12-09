#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

class ResourceManager {

	ResourceManager() = delete;
	static std::unordered_map<std::string, sf::Font> s_fonts;

public:
	static void loadFont(const std::string& t_fontFilename);
	static const sf::Font& getFont(const std::string& t_fontName);
	static void releaseResources();
};

#endif
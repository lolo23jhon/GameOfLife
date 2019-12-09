#ifndef CONFIG_H
#define CONFIG_H


struct Config {


	sf::Color m_bgColor;
	sf::Color m_fgColor;
	unsigned m_cellSize;
	unsigned m_fps;

	sf::Vector2u m_windowSize;
	sf::Vector2u m_simSize;

	Config(const sf::Vector2u& t_winSize, unsigned t_cellSize, const sf::Color& t_fgColor, const sf::Color &t_bgColor, unsigned t_fps);

	void init();
};


#endif 

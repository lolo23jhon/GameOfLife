#include "main.h"



Config::Config(const sf::Vector2u& t_winSize, unsigned t_cellSize, const sf::Color &t_fgColor, const sf::Color& t_bgColor, unsigned t_fps) :
	m_windowSize{ t_winSize }, m_cellSize{ t_cellSize }, m_fgColor{ t_fgColor }, m_bgColor{ t_bgColor }, m_fps{t_fps}
{
	init();
}

void Config::init() {
	m_windowSize.x -= m_windowSize.x % m_cellSize;
	m_windowSize.y -= m_windowSize.y % m_cellSize;

	m_simSize.x = m_windowSize.x / m_cellSize;
	m_simSize.y = m_windowSize.y / m_cellSize;
}
#include "main.h"

FpsCounter::FpsCounter() {

	m_text.move(10, 20);
	m_text.setFillColor(sf::Color::White);

	m_text.setFont(ResourceManager::getFont("CONSOLA"));
	m_text.setCharacterSize(18);
	m_text.setOutlineColor(sf::Color::Black);
	m_text.setOutlineThickness(2);
}


void FpsCounter::update() {
	m_frameCount++;

	if (m_delayTimer.getElapsedTime().asSeconds() > 0.2) {

		m_fps = m_frameCount / m_fpsTimer.restart().asSeconds();
		m_frameCount = 0;
		m_delayTimer.restart();
	}
}

void FpsCounter::draw(sf::RenderTarget& t_renderer) {
	m_text.setString("FPS: " + std::to_string((int)m_fps));
	t_renderer.draw(m_text);
}
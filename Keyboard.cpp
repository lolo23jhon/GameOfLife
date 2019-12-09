#include "main.h"

Keyboard::Keyboard() { std::fill(m_keys.begin(), m_keys.end(), false); }

void Keyboard::update(sf::Event t_e) {
	switch (t_e.type) {
	case sf::Event::KeyPressed:
		m_keys[t_e.key.code] = true;
		break;

	case sf::Event::KeyReleased:
		m_keys[t_e.key.code] = false;
		break;

	default: break;
	};
}

bool Keyboard::isKeyDown(sf::Keyboard::Key t_key)const { return m_keys.at(t_key); }
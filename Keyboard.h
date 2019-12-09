#ifndef KEYBOARD_H
#define KEYBOARD_H


class Keyboard{
public:
	Keyboard();

	void update(sf::Event t_e);
	bool isKeyDown(sf::Keyboard::Key t_key) const;

private:
	std::array<bool, sf::Keyboard::KeyCount> m_keys;

};

#endif
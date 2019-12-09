#ifndef APPLICATION_H
#define APPLICATION_H

class Application {

	std::unique_ptr<CellularAutomaton> m_automaton;

	sf::RenderWindow	m_window;
	FpsCounter			m_fpsCounter;
	Keyboard			m_keyboard;
	sf::Text			m_guiText;
	sf::View			m_view;

	const Config* m_config = nullptr;
	float m_zoom = 1.f;


public:
	static std::unique_ptr<sf::Font> s_font;

	Application(const Config& t_config);

	template <typename T>
	void init() {
		m_automaton = std::make_unique<T>(*m_config,*this);
	}

	void run();
	const sf::RenderWindow& getWindow()const;


private:
	void pollEvents();
	void input(float t_dt);
	void render();
	void resetView();


};



#endif
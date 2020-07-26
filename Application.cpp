#include "main.h"


std::unique_ptr<sf::Font> Application::s_font{ std::make_unique<sf::Font>() };

Application::Application(const Config& t_config) :
	m_window{ {t_config.m_windowSize.x, t_config.m_windowSize.y},"Cellular Automaton" },
	m_config{ &t_config }
{
	

	resetView();
	m_guiText.setFont(ResourceManager::getFont("CONSOLA"));
	m_guiText.move(10, 3);
	m_guiText.setCharacterSize(18);
	m_guiText.setOutlineColor(sf::Color::Black);
	m_guiText.setOutlineThickness(2);

	m_window.setFramerateLimit(t_config.m_fps);
}

void Application::run()
{
	std::cout << "PAUSED: press ENTER on the console window to resume." << std::endl;
	std::cin.get();

	sf::Clock deltaClock;
	unsigned year{ 0 };
	m_window.setKeyRepeatEnabled(false);

	while (m_window.isOpen()) {
		year++;
		m_guiText.setString("Generation: " + std::to_string(year));
		m_fpsCounter.update();
		

		input(deltaClock.restart().asSeconds());

		m_automaton->update();

		render();
		pollEvents();
	}
}

const sf::RenderWindow& Application::getWindow() const { return m_window; }

void Application::pollEvents() {
	sf::Event e;
	while (m_window.pollEvent(e)) {
		m_automaton->input(e);
		m_keyboard.update(e);

		switch (e.type) {

		case sf::Event::Closed:
			m_window.close();
			ResourceManager::releaseResources();
			break;
		}
	}
}


void Application::input(float t_dt) {

	float speed{ 250 };
	sf::Vector2f change;

	if (m_keyboard.isKeyDown(sf::Keyboard::P)) {
		std::cout << "PAUSED: press ENTER on the console window to resume." << std::endl;
		std::cin.get();
	}

	if (m_keyboard.isKeyDown(sf::Keyboard::W)) {
		change.y -= speed;
	}
	else if (m_keyboard.isKeyDown(sf::Keyboard::S)) {
		change.y += speed;
	}

	if (m_keyboard.isKeyDown(sf::Keyboard::A)) {
		change.x -= speed;
	}
	else if (m_keyboard.isKeyDown(sf::Keyboard::D)) {
		change.x += speed;
	}

	if (m_keyboard.isKeyDown(sf::Keyboard::Up)) {
		m_view.zoom(0.95f);
	}

	if (m_keyboard.isKeyDown(sf::Keyboard::Down)) {
		m_view.zoom(1.05f);
	}

	if (m_keyboard.isKeyDown(sf::Keyboard::R)) {
		resetView();
	}

	m_view.move(change * t_dt);
}

void Application::render() {

	// Clear the window
	m_window.setView(m_view);
	m_window.clear();

	// Render the automata pixels
	m_window.setView(m_view);
	m_automaton->render(m_window);

	// Render the GUI
	m_window.setView(m_window.getDefaultView());
	m_window.draw(m_guiText);
	m_fpsCounter.draw(m_window);

	// Show on screen
	m_window.display();
}

void Application::resetView() {
	m_view = sf::View();
	m_view.setCenter({ (float)m_config->m_windowSize.x / 2,(float)m_config->m_windowSize.y / 2 });
	m_view.setSize({ (float)m_config->m_windowSize.x ,(float)m_config->m_windowSize.y });

}


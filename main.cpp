#include "main.h"


// Note: Reources should be deleted before main dies (even if in smart pointers)

int main() {

	ResourceManager::loadFont("Snowballs.ttf");
	ResourceManager::loadFont("CONSOLA.ttf");
	ResourceManager::loadFont("LucidaTypewriterRegular.ttf");

	std::cout << "Running: Conway's Game Of Life" << std::endl;
	Config config{ {g::WINDOW_WIDTH,g::WINDOW_HEIGHT},2u,sf::Color::Green, sf::Color::Black, 30 };
	Application app{ config };
	app.init<GameOfLife>();
	app.run();

}
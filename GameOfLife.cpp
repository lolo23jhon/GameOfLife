#include "main.h"


GameOfLife::GameOfLife(const Config& t_config, const Application& t_application)
	:CellularAutomaton(t_config, t_application), m_cells{ t_config.m_simSize.x * t_config.m_simSize.y }
{
	std::mt19937 rng{ (unsigned)std::time(nullptr) };
	cellForEach([&](unsigned x, unsigned y) {


		unsigned index{ getCellIndex(x,y) };
		std::uniform_int_distribution<int> dist{ 0,1 };


		auto& cell{ m_cells[index] };
		cell = (Cell)dist(rng);
		CellularAutomaton::setCellColor(x, y, cell == Cell::ALIVE ? m_config->m_fgColor : m_config->m_bgColor);
		});
}

void GameOfLife::update() {

	std::vector<std::pair<sf::Vector2i, Cell>> updates;
	cellForEach([&](unsigned x, unsigned y) {

		sf::Vector2i pos{ (int)x,(int)y };
		unsigned aliveNeighbors{ 0 };

		// Check neighbors
		for (int neigh_x{ -1 }; neigh_x <= 1; neigh_x++)
			for (int neigh_y{ -1 }; neigh_y <= 1; neigh_y++) {

				int new_x{ neigh_x + (int)x };
				int new_y{ neigh_y + (int)y };


				if (new_x == -1 || new_x == (int)m_config->m_simSize.x ||
					new_y == -1 || new_y == (int)m_config->m_simSize.y ||
					(neigh_x == 0 && neigh_y == 0))
				{

					continue;
				}


				auto cell{ m_cells[getCellIndex(new_x,new_y)] };
				if (cell == Cell::ALIVE) {
					aliveNeighbors++;

				}
			}
		// Conway's rules
		unsigned index{ getCellIndex(x,y) };
		auto cell{ m_cells[index] };
		switch (cell) {

		case Cell::ALIVE:
			if (aliveNeighbors < 2 || aliveNeighbors > 3) {
				updates.emplace_back(pos, Cell::DEAD);
			}
			break;

		case Cell::DEAD:
			if (aliveNeighbors == 3) {
				updates.emplace_back(pos, Cell::ALIVE);
			}
			break;
		};
		});

	for (auto& update : updates) {
		m_cells[getCellIndex(update.first.x, update.first.y)] = update.second;

		CellularAutomaton::setCellColor(update.first.x, update.first.y, update.second == Cell::ALIVE ? m_config->m_fgColor : m_config->m_bgColor);
	}
}
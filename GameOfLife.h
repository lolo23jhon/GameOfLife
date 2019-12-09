#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H
#include <random> // Needed by its .cpp file

class GameOfLife : public CellularAutomaton {

	enum Cell {
		ALIVE,
		DEAD
	};

public:
	GameOfLife(const Config& t_config, const  Application& t_application);
	void update() override;

private:
	std::vector<Cell> m_cells;
};


#endif 

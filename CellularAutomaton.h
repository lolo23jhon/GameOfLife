#ifndef CELLULAR_AUTOMATON_H
#define CELLULAR_AUTOMATON_H


class CellularAutomaton {
public:
	CellularAutomaton(const Config& t_config, const  Application& t_app);

	virtual void input(const sf::Event& t_e) {}
	virtual void update() = 0;
	virtual void onRenderGui(sf::RenderWindow& t_window) {}
	virtual void onRenderCells(sf::RenderWindow& t_window) {}
	void render(sf::RenderWindow& t_window);


protected:
	const Application const* m_application;
	const Config const* m_config;
	std::vector<sf::Vertex> m_cellVertexPoints;

	unsigned getCellIndex(unsigned t_x, unsigned t_y);
	void setCellColor(unsigned t_x, unsigned t_y, sf::Color t_color);
	template <typename Func>
	void cellForEach(Func t_function);
	void addQuad(unsigned t_xIndex, unsigned t_yIndex);
};

template <typename Func>
void CellularAutomaton::cellForEach(Func t_function) {
	for (unsigned y{ 0 }; y < m_config->m_simSize.y; y++) {
		for (unsigned x{ 0 }; x < m_config->m_simSize.x; x++) {
			t_function(x, y);
		}

	}
}
#endif 

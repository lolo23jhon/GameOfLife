#include "main.h"

CellularAutomaton::CellularAutomaton(const Config& t_config, const Application& t_app) : m_config{ &t_config }, m_application{ &t_app }
{
	m_cellVertexPoints.reserve(m_config->m_simSize.x* m_config->m_simSize.y * 4);
	
	unsigned totalCells{ m_config->m_simSize.x * m_config->m_simSize.y };


	for (unsigned y{ 0 }; y < m_config->m_simSize.y; y++) {
		for (unsigned x{ 0 }; x < m_config->m_simSize.x; x++) {
			addQuad(x, y);
		}
	}
}

void CellularAutomaton::render(sf::RenderWindow& t_window) {
	onRenderCells(t_window);
	t_window.draw(m_cellVertexPoints.data(), m_cellVertexPoints.size(), sf::Quads);
	onRenderGui(t_window);
}

unsigned CellularAutomaton::getCellIndex(unsigned t_x, unsigned t_y) {
	return t_y * m_config->m_simSize.x + t_x;
}

void CellularAutomaton::setCellColor(unsigned t_x, unsigned t_y, sf::Color t_color) {

	auto index{ 4 * (t_y * m_config->m_simSize.x + t_x) };

	for (int i{ 0 }; i < 4; i++) {
		m_cellVertexPoints[index + i].color = t_color;
	}
}

void CellularAutomaton::addQuad(unsigned t_xIndex, unsigned t_yIndex) {
	float cellSize{ (float)m_config->m_cellSize };
	sf::Vertex topLeft;
	sf::Vertex topRight;
	sf::Vertex bottomLeft;
	sf::Vertex bottomRight;

	float pixel_x{ t_xIndex * cellSize };
	float pixel_y{ t_yIndex * cellSize };

	topLeft.position = { pixel_x,pixel_y };
	topRight.position = { pixel_x + cellSize,pixel_y };
	bottomLeft.position = { pixel_x,pixel_y + cellSize };
	bottomRight.position = { pixel_x + cellSize,pixel_y + cellSize };

	m_cellVertexPoints.emplace_back(bottomLeft);
	m_cellVertexPoints.emplace_back(bottomRight);
	m_cellVertexPoints.emplace_back(topRight);
	m_cellVertexPoints.emplace_back(topLeft);

}
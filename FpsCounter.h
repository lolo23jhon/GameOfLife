#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H



class FpsCounter {
private:
	sf::Text m_text;
	sf::Font m_font;
	sf::Clock m_delayTimer;
	sf::Clock m_fpsTimer;

	float m_fps = 0;
	int m_frameCount = 0;


public:
	FpsCounter();
	void update();
	void draw(sf::RenderTarget& t_renderer);

};


#endif
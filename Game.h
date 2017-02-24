#pragma once
#include <SFML/Graphics.hpp>
#include "Levels.h"
#include <vector>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "SFML-Project"

class Game
{
private:
	TextureManager			m_textureManager;
	sf::View				m_view;
    sf::Clock				m_clock;
    float					m_time;
	sf::RenderWindow		m_window;
	
	std::vector<Level*>		m_levels;
	int						m_currentLevel;
private:
	void update();
	void draw();
	void event();
	void loadTexturesFromFiles();
	void loadLevels();
	void loadTextureInLevels();
public:
	Game();
	void timeTick();
	void loop();
};

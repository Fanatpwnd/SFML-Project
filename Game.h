#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TextureManager.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "SFML-Project"

class Game
{
private:
	TextureManager tex_manager;
	sf::View view;

    sf::Clock clock;
    float time;

	Player player;
private:
	void update();
	void draw();
	void event();	
	void loadPlayer();
public:
	
    sf::RenderWindow window;

	Game();
	
	void timeTick();
	void loop();
};

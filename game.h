#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"

enum Game_State {PAUSE, MENU, GAME};

class Game
{
private:
	sf::CircleShape circle;
	Player player;
	//Levels
	//State Game
	Game_State state;
	sf::Clock clock;
	float time;
	sf::Texture texture;
	sf::Texture tBackground;
	sf::Sprite sBackground;
public:
	Game();
	void update();
	void draw(sf::RenderWindow *window);
	void event(sf::Event *ev, sf::RenderWindow *win);

};
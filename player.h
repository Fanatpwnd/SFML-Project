#pragma once
#include <SFML/Graphics.hpp>
enum Player_state{FALL, JUMP, STAY};
enum Player_move{LEFT, RIGHT, NO};

class Player
{
	sf::Sprite sprite;
	Player_state player_state;
	Player_move player_move;
	float speedx, speedy;
	float jump_time;
	sf::Clock clock;

public:
	Player();
	void jump();
	void move();
	void draw(sf::RenderWindow *ren);
	void setTexture(sf::Texture *tex);
	void event(sf::Event *ev);
	void update(float time);
	
};
#pragma once
#include <SFML\Graphics.hpp>
#include "AnimationManager.h"
#include <vector>


enum State { FALL, JUMP, STAY };
enum Move{ LEFT, RIGHT, NO };

class Player
{
private:
	
	AnimationManager*	m_animationManager;

	float				speedx, speedy;
	float				jumpTime;
	int					jumpCount;
	sf::Sprite			sprite;
	sf::Clock			clock;
	State				pState;
	Move				pMove;

private:
	void move();
	void jump();
	bool keyPressed(sf::Keyboard::Key key, sf::Event *ev);
	bool keyRealesed(sf::Keyboard::Key key, sf::Event *ev);

	void initAnimation();

public:
	Player();
	~Player();

	void draw(sf::RenderWindow *window);
	void update(float time);
	void setTexture(sf::Texture *texture);
	void event(sf::Event *ev);
	void setPosition(float x, float y);
	const sf::Vector2f getPosition();
	const sf::Texture* getTexture();
	const sf::FloatRect getRect();


};

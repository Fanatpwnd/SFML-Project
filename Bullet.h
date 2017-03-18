#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"
#include "AnimationManager.h"
#include <SFML\Graphics.hpp>

class Bullet :public Entity{
	AnimationManager*	m_animationManager;
	bool				isLife;
	sf::Sprite			m_sprite;

public:
	Bullet(sf::Texture *texture, float x, float y);
	~Bullet();

	void draw(sf::RenderWindow *window);
	void update(float time);
	void setTexture(sf::Texture *texture);
	void setPosition(float x, float y);
};

#endif
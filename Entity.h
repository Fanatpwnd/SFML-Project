#pragma once
#include <SFML\Graphics.hpp>

class Entity
{
	//float x, y;
	
public:
	sf::Sprite m_sprite;
};

class Wall : public Entity {
public:
	Wall();

	void draw(sf::RenderWindow *window);
	void setTexture(sf::Texture *texture);
	void setPosition(float x, float y);
	const sf::Vector2f getPosition();
	const sf::Texture* getTexture();
	const sf::FloatRect getRect();

};
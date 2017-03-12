#include "Entity.h"

Wall::Wall()
{
	m_sprite.setPosition(200, 0);
	m_sprite.setScale(0.5f, 0.5f);
}

void Wall::draw(sf::RenderWindow *window)
{
	window->draw(m_sprite);
}

void Wall::setTexture(sf::Texture *texture)
{
	m_sprite.setTexture(*texture);
}

void Wall::setPosition(float x, float y)
{
	m_sprite.setPosition(x, y);
}

const sf::Vector2f Wall::getPosition()
{
	return m_sprite.getPosition();
}

const sf::Texture* Wall::getTexture()
{
	m_sprite.getTexture();
}

const sf::FloatRect Wall::getRect()
{
	return m_sprite.getGlobalBounds();
}
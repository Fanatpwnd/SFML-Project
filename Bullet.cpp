#include "Bullet.h"

Bullet::Bullet(sf::Texture *texture, float x, float y){
	//m_animationManager = new AnimationManager(&m_sprite);
	
	setTexture(texture);
	setPosition(x, y);

	isLife = true;
}

Bullet::~Bullet(){
	delete m_animationManager;
}

void Bullet::draw(sf::RenderWindow *window){
	window->draw(m_sprite);
}
void Bullet::update(float time){}

void Bullet::setTexture(sf::Texture *texture){
	m_sprite.setTexture(*texture);
}

void Bullet::setPosition(float x, float y){
	m_sprite.setPosition(x, y);
}
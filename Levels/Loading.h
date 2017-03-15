#pragma once
#include "../Level.h"

class Load: public Level
{
	sf::Sprite load;
	sf::Texture tex;
public:
	void loadTextures(TextureManager* tex_manager){ tex.loadFromFile("load.jpg"); load.setTexture(tex); load.setPosition(0,0);}
	void draw(sf::RenderWindow* window){window->draw(load);}
	void update(float time){}
	void event(sf::Event* ev){}
};

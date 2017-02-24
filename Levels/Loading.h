#pragma once
#include "../Level.h"

class Load: public Level
{
public:
	void loadTextures(TextureManager* tex_manager){}
	void draw(sf::RenderWindow* window){}
	void update(float time){}
	void event(sf::Event* ev){}
};

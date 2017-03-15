#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TextureManager.h"

class Level
{
public:
	virtual void loadTextures(TextureManager* tex_manager) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual void update(float time) = 0;
	virtual void event(sf::Event* ev) = 0;
};
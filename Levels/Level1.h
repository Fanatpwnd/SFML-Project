#pragma once
#include "../Level.h"

class Level1: public Level
{
	Player player;
	sf::Sprite background;
public:
	Level1(){printf("Creating level 1...\n");}
	void loadTextures(TextureManager* tex_manager)
	{
		player.setTexture(tex_manager->getTexture("player"));
		background.setTexture(*tex_manager->getTexture("background"));
	}

	void draw(sf::RenderWindow* window)
	{
		window->draw(background);
		player.draw(window);
	}
	void update(float time)
	{
		player.update(time);
	}

	void event(sf::Event* ev)
	{
		player.event(ev);
	}
};

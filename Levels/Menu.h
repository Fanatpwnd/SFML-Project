#pragma once
#include "../Level.h"


class Menu: public Level
{
	sf::Sprite button1, button2;
	sf::Sprite background;
public:
	void draw(sf::RenderWindow* window)
	{
		window->draw(background);
		window->draw(button1);
		window->draw(button2);
	}
	
	void update(float time)
	{
	}
	
	void event(sf::Event* ev)
	{
	}
	
	void loadTextures(TextureManager* tex_manager)
	{
	
	}
	
	Menu()
	{
		printf("Creating menu...\n");
	}
};
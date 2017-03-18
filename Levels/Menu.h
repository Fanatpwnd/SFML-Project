#pragma once
#include "../Level.h"


class Menu: public Level
{
	Player player;
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

	//tmp method O_o
	//getting player's coordinates in loading...it's strange..
	//anyway it's only tmp
	sf::FloatRect getPlayerRect(){
		return player.getRect();
	}

};
#pragma once
#include "../Level.h"

class Level2: public Level
{
	Player player;
	sf::Sprite background;
public:
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
	
	void loadTextures(TextureManager* tex_manager)
	{
		player.setTexture(tex_manager->getTexture("player2"));
		background.setTexture(*tex_manager->getTexture("background2"));
	}
	
	Level2()
	{
		printf("Creating level 2...\n");
	}

	//tmp method
	sf::FloatRect getPlayerRect(){
		return player.getRect();
	}
};
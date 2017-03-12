#include "Game.h"
#include <Windows.h>

Game::Game()
{
	printf("Create game...\n");
	view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	view.setCenter(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

	loadPlayer();
}

void Game::loadPlayer()
{
	tex_manager.loadTexture("res/player.png", "player");
	player.setTexture(tex_manager.getTexture("player"));
	player.setPosition(100.0f, 100.0f);
}

void Game::update()
{
	player.update(time);
}

void Game::event()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		player.event(&event);
	}	
}

void Game::draw()
{
	window.clear();
	player.draw(&window);
	window.display();
}

void Game::timeTick()
{
	time = clock.getElapsedTime().asSeconds();
    clock.restart();
}


void Game::loop()
{
	printf("Start game... \n");
	while(window.isOpen())
	{
		timeTick();
		event();
		update();
		draw();
	}
}
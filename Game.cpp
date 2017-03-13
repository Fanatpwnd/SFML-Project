#include "Game.h"
#include <Windows.h>

Game::Game()
{
	printf("Create game...\n");
	view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	view.setCenter(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	tex_manager.loadTexture("load.jpg", "wall");
	loadPlayer();
	walls.push_back(*(new Wall(100, 300, tex_manager.getTexture("wall"))));
	walls.push_back(*(new Wall(200, 400, tex_manager.getTexture("wall"))));
	walls.push_back(*(new Wall(300, 500, tex_manager.getTexture("wall"))));
	player.setPosition(.0f, 100.0f);
}

void Game::loadPlayer()
{
	tex_manager.loadTexture("player2.jpg", "player");
	player.setTexture(tex_manager.getTexture("player"));
}

void Game::update()
{
	debuger.clear();
	player.update(time);
	for (auto i = walls.begin(); i != walls.end(); ++i) player.collision(&(*i));
	debuger.addRect(player.getRect());
	for (auto i = walls.begin(); i != walls.end(); ++i) debuger.addRect(i->getRect());
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
		debuger.event(&event);
	}	
}

void Game::draw()
{
	window.clear();
	for (auto i = walls.begin(); i != walls.end(); ++i) i->draw(&window);
	player.draw(&window);
	debuger.draw(&window);
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
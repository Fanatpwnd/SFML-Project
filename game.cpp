#include "game.h"

Game::Game()
{
	circle.setRadius(20);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(100, 100);
	state = MENU;
	tex_manager.loadTexture("logo.png", "player");
	player.setTexture(tex_manager.getTexture("player"));

	//texture.loadFromFile("logo.png");
	//player.setTexture(&texture);
	

	tex_manager.loadTexture("background.jpg", "background");
	sBackground.setTexture(*tex_manager.getTexture("background"));

	//tBackground.loadFromFile("background.jpg");
	//sBackground.setTexture(tBackground);
}

void Game::update()
{
	time = clock.restart().asSeconds();
	player.update(time);
	//logic
}

void Game::event(sf::Event *ev, sf::RenderWindow *win)
{
	player.event(ev);
	//event
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		win->close();
	}
		
}

void Game::draw(sf::RenderWindow *window)
{
	window->clear();
	//draw
	window->draw(sBackground);
	player.draw(window);
	window->draw(circle);
	window->display();
}
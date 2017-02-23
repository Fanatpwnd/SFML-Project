#include "Levels.h"

void Level1::draw(sf::RenderWindow* window)
{
	window->draw(background);
	player.draw(window);
	printf("Draw \n");
}

void Level1::update(float time)
{
	player.update(time);
}

void Level1::event(sf::Event* ev)
{
	player.event(ev);
}

void Level1::loadTextures(TextureManager* tex_manager)
{
	player.setTexture(tex_manager->getTexture("player"));
	//test.loadFromFile("player.png");
	//player.setTexture(&test);
	background.setTexture(*tex_manager->getTexture("background"));
}

void Level2::draw(sf::RenderWindow* window)
{
	window->draw(background);
	player.draw(window);
}

void Level2::update(float time)
{
	player.update(time);
}

void Level2::event(sf::Event* ev)
{
	player.event(ev);
}

void Level2::loadTextures(TextureManager* tex_manager)
{
	player.setTexture(tex_manager->getTexture("player"));
}

void Menu::draw(sf::RenderWindow* window)
{
	window->draw(background);
	window->draw(button1);
	window->draw(button2);
}

void Menu::update(float time)
{
}

void Menu::event(sf::Event* ev)
{
}

void Menu::loadTextures(TextureManager* tex_manager)
{

}

Level1::Level1()
{
	printf("Creating level 1...\n");
}

Level2::Level2()
{
	printf("Creating level 2...\n");
}

Menu::Menu()
{
	printf("Creating menu...\n");
}
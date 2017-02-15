#include <SFML\Graphics.hpp>
#include "game.h"

void main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Platformer");
	Game game;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			game.event(&event, &window);
		}
		game.update();

		game.draw(&window);
	}
}
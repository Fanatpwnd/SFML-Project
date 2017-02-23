#include "Level.h"

class Level1: public Level
{
	Player player;
	sf::Texture test;
public:
	Level1();
	void loadTextures(TextureManager* tex_manager);
	void draw(sf::RenderWindow* window);
	void update(float time);
	void event(sf::Event* ev);
};

class Level2: public Level
{
	Player player;
public:
	Level2();
	void loadTextures(TextureManager* tex_manager);
	void draw(sf::RenderWindow* window);
	void update(float time);
	void event(sf::Event* ev);
};

class Menu: public Level
{
	sf::Sprite button1, button2;
public:
	Menu();
	void loadTextures(TextureManager* tex_manager);
	void draw(sf::RenderWindow* window);
	void update(float time);
	void event(sf::Event* ev);
};
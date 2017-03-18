#include "Game.h"
#include <Windows.h>
#include <list>
#include "Bullet.h"

void Game::update()
{
	m_levels[m_currentLevel]->update(m_time);
}

void Game::event()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			m_currentLevel = 1;
			printf("Select 1 level \n");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			m_currentLevel = 2;
			printf("Select 2 level \n");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			m_currentLevel = 3;
			printf("Select 3 level \n");
		}
		m_levels[m_currentLevel]->event(&event);

		//temporarily it will be here///////////////////////////////
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			bullets.push_back(new Bullet(m_textureManager.getTexture("bullet"),
				m_levels[m_currentLevel]->getPlayerRect().left,
				m_levels[m_currentLevel]->getPlayerRect().top));
			printf("I'm create a bullet!");
		}
		/////////////////////////////////////////////////////////////
	}	
}

void Game::draw()
{


	m_window.clear();
	m_levels[m_currentLevel]->draw(&m_window);

	////////////////////////////tmp//////////////////////
	std::list<Bullet*>::iterator it;
	for (it = bullets.begin(); it != bullets.end(); it++){
		(*it)->draw(&m_window);
	}
	/////////////////////////////////////////////////////



	m_window.display();
}

Game::Game()
{
	printf("Create game...\n");
	m_view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	m_view.setCenter(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
	m_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	loadTexturesFromFiles();
	loadLevels();
	loadTextureInLevels();
	
}

void Game::loadTexturesFromFiles()
{
	m_textureManager.loadTexture("res/player.png", "player");
	Sleep(1000);
	m_textureManager.loadTexture("background.jpg", "background");
	Sleep(1000);
	m_textureManager.loadTexture("player2.jpg", "player2");
	Sleep(1000);
	m_textureManager.loadTexture("background2.jpg", "background2");
	Sleep(1000);
	m_textureManager.loadTexture("res/bullet.png", "bullet");
	Sleep(1000);

	m_textureManager.printListName();
}

void Game::loadTextureInLevels()
{
	printf("Load Textures in level...\n");
	for (int i = 0; i < m_levels.size(); i++)
	{
		m_levels[i]->loadTextures(&m_textureManager);
	}
}

void Game::loadLevels()
{
	printf("Load levels...\n");
	m_levels.push_back(new Load);
	m_levels.push_back(new Level1);
	m_levels.push_back(new Level2);
	m_levels.push_back(new Menu);
	m_currentLevel = 0;
}

void Game::loop()
{
	//temporarily it will be here///
	//std::list<Bullet*>::iterator it;
	////////////////////////////////

	printf("Start game... \n");
	while(m_window.isOpen())
	{
		timeTick();
		event();
		update();
		draw();

		//temporarily it will be here////////////////////////////
		//for (it = bullets.begin(); it != bullets.end(); it++){
			//(*it)->update(m_time);
	//	}
		////////////////////////////////////////////////////////
	}
}

void Game::timeTick()
{
	m_time = m_clock.getElapsedTime().asSeconds();
    m_clock.restart();
}

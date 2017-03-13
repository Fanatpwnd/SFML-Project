#pragma once
#include "Debuger.h"

	Debuger::Debuger()
	{
		isDraw = false;
		font.loadFromFile("Determination.ttf");
		text.setFont(font);
	}

	void Debuger::addRect(sf::FloatRect rect){
		sf::RectangleShape temp;
		temp.setSize(sf::Vector2f(rect.height, rect.width));
		temp.setPosition(sf::Vector2f(rect.left, rect.top));
		temp.setOutlineColor(sf::Color::Green);
		temp.setOutlineThickness(3);
		temp.setFillColor(sf::Color::Transparent);
		conturs.push_back(temp);
	}	

	void Debuger::addRect(sf::IntRect rect){
		sf::RectangleShape temp;
		temp.setSize(sf::Vector2f(rect.height, rect.width));
		temp.setPosition(sf::Vector2f(rect.left, rect.top));
		temp.setOutlineColor(sf::Color::Green);
		temp.setOutlineThickness(3);
		temp.setFillColor(sf::Color::Transparent);
		conturs.push_back(temp);
	}

	void Debuger::draw(sf::RenderWindow* window){
		
		
		if (isDraw){
			for (int i = 0; i < conturs.size(); i++){
				window->draw(conturs[i]);
			}
			window->draw(text);
		}

		if (isDraw)
		{
			for (int i = 0; i < conturs.size(); i++)
			{
				if (conturs[i].getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*window)))
					text.setString("Left: " + std::to_string(conturs[i].getGlobalBounds().left) +
					" Top: " + std::to_string(conturs[i].getGlobalBounds().top) +
					"\n Width: " + std::to_string(conturs[i].getGlobalBounds().width) + 
					" Height: " + std::to_string(conturs[i].getGlobalBounds().height));
			}
		}
	}

	void Debuger::event(sf::Event* ev){
		if ((ev->type == sf::Event::KeyReleased) &&
			(ev->key.code == sf::Keyboard::Tab)) { 
				if (isDraw) isDraw = false;
				else isDraw = true;
		}
		
	} 

	void Debuger::clear()
	{
		conturs.clear();
	}


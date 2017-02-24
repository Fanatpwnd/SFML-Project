#pragma once
#include <SFML/Graphics.hpp>
#include <map>


class TextureManager
{
	std::map<std::string, sf::Texture> manager;
	int count_noname;
	void addTexture(sf::Texture* tex, const std::string str);
public:
	TextureManager();													//Конструктор
	sf::Texture* getTexture(const std::string str);						//Вернуть ссылку на текстуру
	int getSize();														//Вернуть кол-во текстур в менеджере
	void loadTexture(const std::string str, const std::string name);	//Загрузить текстуру (с заданым именем)
	void loadTexture(const std::string str);							//Загрузить текстуру (с дефолтным именем "texture#")
	void printListName();												//Печать имен текстур в консоль
};
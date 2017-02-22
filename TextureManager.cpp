#include "TextureManager.h"


	TextureManager::TextureManager()
	{
		count_noname = 1;
	}

	void TextureManager::addTexture(sf::Texture* tex, const std::string str = "-1")
	{
		std::string tmp_str;
		if (str == "-1") { tmp_str = "texture" + std::to_string(count_noname); count_noname++; }
		else tmp_str = str;

		manager.insert(std::pair<std::string, sf::Texture>(tmp_str, *tex));
		printf("Texture %s added in TM.\n", tmp_str.c_str());
	}

	sf::Texture* TextureManager::getTexture(const std::string str)
	{
		std::map<std::string, sf::Texture>::iterator it;
		it = manager.find(str);
		printf("Texture %s got from TM.\n", str.c_str());
		return &(it->second);
	}

	int TextureManager::getSize()
	{
		return manager.size();
	}

	void TextureManager::loadTexture(const std::string str, const std::string name)
	{
		sf::Texture tmp;
		tmp.loadFromFile(str);
		addTexture(&tmp, name);
	}

	void TextureManager::loadTexture(const std::string str)
	{
		sf::Texture tmp;
		tmp.loadFromFile(str);
		addTexture(&tmp);
	}

	void TextureManager::printListName()
	{
		std::map<std::string, sf::Texture>::iterator it;
		printf("Texture List (%d): \n", getSize());
		for (it = manager.begin(); it != manager.end(); ++it)
			printf("%s \n", it->first.c_str());
	}
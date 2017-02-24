#pragma once
#include <SFML/Graphics.hpp>
#include <map>


class TextureManager
{
	std::map<std::string, sf::Texture> manager;
	int count_noname;
	void addTexture(sf::Texture* tex, const std::string str);
public:
	TextureManager();													//�����������
	sf::Texture* getTexture(const std::string str);						//������� ������ �� ��������
	int getSize();														//������� ���-�� ������� � ���������
	void loadTexture(const std::string str, const std::string name);	//��������� �������� (� ������� ������)
	void loadTexture(const std::string str);							//��������� �������� (� ��������� ������ "texture#")
	void printListName();												//������ ���� ������� � �������
};
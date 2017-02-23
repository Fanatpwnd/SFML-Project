#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TextureManager.h"

class Level
{
protected:
	sf::Sprite background;
public:
	virtual void loadTextures(TextureManager* tex_manager);
	virtual void draw(sf::RenderWindow* window);
	virtual void update(float time);
	virtual void event(sf::Event* ev);
};
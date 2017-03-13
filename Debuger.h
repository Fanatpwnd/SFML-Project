#include <SFML/Graphics.hpp>
#include <vector>

class Debuger
{
	std::vector<sf::RectangleShape> conturs;
	sf::Text text;
	sf::Font font;
	bool isDraw;
public:
	Debuger();
	void addRect(sf::FloatRect rect);
	void addRect(sf::IntRect rect);
	void draw(sf::RenderWindow* window);
	void event(sf::Event* ev);
	void clear();
};


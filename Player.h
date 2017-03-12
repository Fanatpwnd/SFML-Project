#include <SFML\Graphics.hpp>
#include "Entity.h"
enum State { FALL, JUMP, STAY };
enum Move{ LEFT, RIGHT, NO };

class Player
{
private:
	float speedx, speedy;
	float jumpTime;
	sf::Clock clock;
	Move pMove;

private:
	void move();
	void jump();
	//State getState();
	//Move getMoveState();
	bool keyPressed(sf::Keyboard::Key key, sf::Event *ev);
	bool keyRealesed(sf::Keyboard::Key key, sf::Event *ev);


public:
	int jumpCount;
	State pState;
	sf::Sprite sprite;
	Player();
	void draw(sf::RenderWindow *window);
	void update(float time);
	void setTexture(sf::Texture *texture);
	void event(sf::Event *ev);
	void setPosition(float x, float y);
	void collision(Entity* entity); //Коллизия =)
	const sf::Vector2f getPosition();
	const sf::Texture* getTexture();
	const sf::FloatRect getRect();	
};
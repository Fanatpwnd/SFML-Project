#include "Player.h"
#define SPEEDX 300
#define JUMPNUMBER 2
#define SPEEDJUMP 600
#define SPEEDFALL 400.0f
#define TIMEJUMP 0.2

Player::Player()
{
	jumpCount = 0;
	pState = FALL;
	pMove = NO;
	speedx = 0;
	speedy = 0;
}

/*State Player::getState()
{
	if ( (pState == STAY) || (jumpCount < JUMPNUMBER) )
		return JUMP;

}

Move Player::getMoveState()
ent
}*/

bool Player::keyPressed(sf::Keyboard::Key key, sf::Event *ev)
{
	return ((ev->type == sf::Event::KeyPressed) &&
		(ev->key.code == key));
}

bool Player::keyRealesed(sf::Keyboard::Key key, sf::Event *ev)
{
	return ((ev->type == sf::Event::KeyReleased) &&
		(ev->key.code == key));
}

void Player::event(sf::Event *ev)
{
	if (keyPressed(sf::Keyboard::Left, ev))
	{
		pMove = LEFT;
	}

	if (keyPressed(sf::Keyboard::Right, ev))
	{
		pMove = RIGHT;
	}

	if (keyRealesed(sf::Keyboard::Left, ev) ||
		keyRealesed(sf::Keyboard::Right, ev))
	{
		pMove = NO;
	}

	if (keyPressed(sf::Keyboard::Space, ev))
	{
		jump();
	}
}

void Player::draw(sf::RenderWindow *window)
{
	window->draw(sprite);
}

void Player::move()
{
	sprite.move(speedx, speedy);
}

void Player::jump()
{
	if ((pState == STAY) || (jumpCount < JUMPNUMBER))
	{
		pState = JUMP;
		jumpTime = clock.getElapsedTime().asSeconds();
		jumpCount++;
	}
}

void Player::update(float time)
{
	move();
	//printf("time = %f speedy = %f speed fall = %f\n", time, speedy, SPEEDFALL);
	switch (pMove)
	{

	case LEFT:
	{
		speedx = -SPEEDX * time;
		break;
	}

	case RIGHT:
	{
		speedx = SPEEDX * time;
		break;
	}

	case NO:
	{
		speedx = 0;
		break;
	}

	}

	switch (pState)
	{

	case JUMP:
	{
		speedy = -SPEEDJUMP * time;
		if (clock.getElapsedTime().asSeconds() - jumpTime
			>= TIMEJUMP)
		{
			pState = FALL;
		}
		break;
	}

	case FALL:
	{
		speedy = SPEEDFALL * time;
		if (sprite.getPosition().y >= 500.0f)
		{
			pState = STAY;
			jumpCount = 0;
		}
		break;
	}

	case STAY:
	{
		speedy = 0;
		break;
	}

	}

}

void Player::setTexture(sf::Texture *texture)
{
	sprite.setTexture(*texture);
}

void Player::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

const sf::Vector2f Player::getPosition()
{
	return sprite.getPosition();
}

const sf::Texture* Player::getTexture()
{
	return sprite.getTexture();
}

const sf::Rect<float> Player::getRect()
{
	return sprite.getGlobalBounds();
}
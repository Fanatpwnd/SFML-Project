#include "Player.h"

#define SPEEDX 300
#define JUMPNUMBER 2
#define SPEEDJUMP 600
#define SPEEDFALL 400
#define TIMEJUMP 0.2

Player::Player()
{
	speedx = speedy = 0.0f;
	jumpCount = 0;
	pState = FALL;
	pMove = NO;
	sprite.setScale(0.2f, 0.2f);
}



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
		///////////Temp floor////////////////
		if (sprite.getPosition().y > 500)
		{
			pState = STAY;
			setPosition(getPosition().x, 500);
			jumpCount = 0;
		}
		//////////////////////////////////////
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

void Player::collision(Entity* entity)
{	
	sf::FloatRect pl = sprite.getGlobalBounds();
	sf::FloatRect en = entity->m_sprite.getGlobalBounds();
	//printf("Player: left = %f top = %f wigth = %f height = %f || Entity: left = %f top = %f wight = %f height = %f \n",
	//	pl.left, pl.top, pl.width, pl.height, en.left, en.top, en.width, en.height);

	/////////////////////////////////////////Достойный ptintf///////////////////////////////////////////////
	///printf("pl.left + pl.width = %f en.left = %f || pl.left + pl.width = %f en.left + en.width = %f ",///
	//////pl.left + pl.width, en.left, pl.left + pl.width, en.left + en.width*2);///////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
		/*if ((sprite.getPosition().y + sprite.getGlobalBounds().height) >= (entity->m_sprite.getPosition().y)
			&& (sprite.getPosition().x + sprite.getGlobalBounds().width) >= (entity->m_sprite.getPosition().x) //Левый край
			&& (sprite.getPosition().x + sprite.getGlobalBounds().width) <= (entity->m_sprite.getPosition().x + entity->m_sprite.getGlobalBounds().width))
		
		*/
		if (   (pl.top + pl.height) >= (en.top)
			&& (pl.left + pl.width) >= (en.left)
			&& (pl.left + pl.width/1.2) <= (en.left + en.width*1.5))
		{
			pState = STAY;
			jumpCount = 0;
			sprite.setPosition(sf::Vector2f(pl.left,en.top - pl.height));
		}
		else if (((en.top < pl.top+pl.height) || (en.top + en.height > pl.top)) && (pl.left+pl.width >= en.left) && (pl.left + pl.width < en.left+10))
		{
			
			pMove = NO;
			sprite.setPosition(sf::Vector2f(en.left, pl.top));
		}
		else if ((pl.left <= en.left+en.width) && (pl.left > en.left+en.width - 10))
		{
			pMove = NO;
			sprite.setPosition(sf::Vector2f(en.left+en.width, pl.top));
		}
	

}
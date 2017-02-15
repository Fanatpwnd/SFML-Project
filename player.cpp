#include "player.h"
#define SPEEDX 300
#define SPEEDJUMP 400
#define SPEEDFALL 400
#define TIME_JUMP 0.2

Player::Player()
{
	player_state = FALL;
	player_move = NO;
	sprite.setPosition(200, 200);
	sprite.setScale(0.5f, 0.5f);
}

void Player::jump()
{
	if (player_state == STAY)
	{
		player_state = JUMP;
	}
}

void Player::move()
{
	sprite.move(speedx, speedy);
}

void Player::draw(sf::RenderWindow *ren)
{
	ren->draw(sprite);
}

void Player::setTexture(sf::Texture *tex)
{
	sprite.setTexture(*tex);
}

void Player::event(sf::Event *ev)
{
	if ((ev->type = sf::Event::KeyPressed) && 
		(ev->key.code == sf::Keyboard::Left ))
	{
		player_move = LEFT;
		
	}
	if ((ev->type = sf::Event::KeyPressed) &&
		(ev->key.code == sf::Keyboard::Right))
	{
		player_move = RIGHT;
	}

	if ((ev->type = sf::Event::KeyPressed) &&
		(ev->key.code == sf::Keyboard::Space)
		&& (player_state==STAY))
	{
		player_state = JUMP;
		jump_time = clock.getElapsedTime().asSeconds();
	}

}

void Player::update(float time)
{
	move();
	//printf("y:%f \n", sprite.getPosition().y);
	if (player_move == LEFT)
	{
		speedx = -SPEEDX * time;
	}

	if (player_move == RIGHT)
	{
		speedx = SPEEDX * time;
	}
	if (player_move == NO)
	{
		speedx = 0;
	}

	if (player_state == JUMP)
	{
		speedy = -SPEEDJUMP * time;
		if (clock.getElapsedTime().asSeconds() - jump_time 
			>= TIME_JUMP)
		{
			player_state = FALL;
		}
	}

	if (player_state == FALL)
	{
		speedy = SPEEDFALL * time;
		if (sprite.getPosition().y >= 300.0)
		{
			player_state = STAY;
		}
	}

	if (player_state == STAY)
	{
		speedy = 0;
	}
}
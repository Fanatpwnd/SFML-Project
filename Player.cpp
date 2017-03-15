#include "Player.h"
#define SPEEDX 200
#define JUMPNUMBER 2
#define SPEEDJUMP 600
#define SPEEDFALL 400.0f
#define TIMEJUMP 0.2

Player::Player()
{
	m_animationManager = new AnimationManager(&sprite);
	initAnimation();

	jumpCount = 0;
	pState = FALL;
	pMove = NO;
	speedx = 0;
	speedy = 0;
	sprite.setScale(1.5f, 1.5f);

	isFalled = false;
}

Player::~Player(){
	delete m_animationManager;
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
		m_orientation = LEFT_SIDE;
	}

	if (keyPressed(sf::Keyboard::Right, ev))
	{

		pMove = RIGHT;
		m_orientation = RIGHT_SIDE;
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

void Player::draw(sf::RenderWindow* window)
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
		case LEFT:{
			speedx = -SPEEDX * time;

			m_animationManager->playAnimation("leftMove", time);

			break;
		}

		case RIGHT:{
			speedx = SPEEDX * time;
			
			m_animationManager->playAnimation("rightMove", time);

			break;
		}

		case NO:{
			speedx = 0;
			break;
		}
	}

	switch (pState)
	{
		case JUMP:{

			if (m_orientation == RIGHT_SIDE){
				m_animationManager->playAnimation("rightJump", time);
			}
			else if (m_orientation == LEFT_SIDE){
				m_animationManager->playAnimation("leftJump", time);
			}
			
			speedy = -SPEEDJUMP * time;
			if (clock.getElapsedTime().asSeconds() - jumpTime
				>= TIMEJUMP)
			{
				pState = FALL;
			}
			break;
		}

		case FALL:{
			
			isFalled = true;

			if (m_orientation == RIGHT_SIDE){
				m_animationManager->playAnimation("rightFall", time);
			}
			else if (m_orientation == LEFT_SIDE){
				m_animationManager->playAnimation("leftFall", time);
			}

			speedy = SPEEDFALL * time;
			if (sprite.getPosition().y >= 500.0f)
			{
				pState = STAY;
				jumpCount = 0;
			}
			break;
		}

		case STAY:{
			//bicycle number 1 starting here ^^
			if (isFalled){
				if (m_orientation == RIGHT_SIDE){ m_animationManager->playAnimation("rightMove", time); }
				else if (m_orientation == LEFT_SIDE){ m_animationManager->playAnimation("leftMove", time); }
				isFalled = false;
			}
			//bicycle number 1 finished here ^^
			

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

void Player::initAnimation(){
	m_animationManager->addAnimation("rightMove");
	m_animationManager->addAnimation("leftMove");

	m_animationManager->addAnimation("leftJump");
	m_animationManager->addAnimation("rightJump");

	m_animationManager->addAnimation("leftFall");
	m_animationManager->addAnimation("rightFall");

	m_animationManager->initFrames("rightMove", 56, 560, 56, 80, 3);
	m_animationManager->initFrames("leftMove", 56, 560, 56, 80, 3, true);

	m_animationManager->addFrame("rightJump", 56, 160, 56, 80);
	m_animationManager->addFrame("leftJump", 112, 160, -56, 80);

	m_animationManager->addFrame("rightFall", 112, 160, 56, 80);
	m_animationManager->addFrame("leftFall", 168, 160, -56, 80);
}
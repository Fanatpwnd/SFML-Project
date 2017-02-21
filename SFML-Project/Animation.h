#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
/*It's the class animation
I think there is one type of animation. For example jump, run, shoot, etc.
*/
class Animation{

	sf::Sprite sprite;
	std::vector<sf::IntRect> frames;
	std::vector<sf::IntRect> frames_inverted;
	float currentFrame;
	float speed;


public:
	bool isInverted; // this variable show: display inverted frame or not
	bool isPlaying;

	Animation(sf::Texture &t, float x, float y, float width, float height, float speed, int framesCount, int step);

	void playingAnimation(float time);//This method is playing the animation

	sf::Sprite getSprite();
	std::vector<sf::IntRect> &getFrames();
	std::vector<sf::IntRect> &getInvertedFrames();
	float getCurrentFrame();
	float getSpeed();
};
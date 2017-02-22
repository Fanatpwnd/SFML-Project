#include <SFML/Graphics.hpp>
#include "Animation.h"

Animation::Animation(sf::Texture &t, float x, float y, float width, float height, float speed, int framesCount, int step){
	this->speed = speed;
	sprite.setTexture(t);
	currentFrame = 0;
	isPlaying = true;
	isInverted = false;

	for (int i = 0; i < framesCount; i++){
		frames.push_back(sf::IntRect(x + i*step, y, width, height));
		frames_inverted.push_back(sf::IntRect(x + i*step, y, -width, height));
	}
}

void Animation::tick(float time){
	if (!isPlaying){ return; }

	currentFrame += speed * time;
	if (currentFrame > frames.size()){ currentFrame -= frames.size(); }


	if (isInverted) { sprite.setTextureRect(frames[(int)currentFrame]); }
	else{ sprite.setTextureRect(frames[(int)currentFrame]); }
}

float Animation::getCurrentFrame(){ return currentFrame; }
float Animation::getCurrentFrame(){ return currentFrame; }
float Animation::getSpeed(){ return speed; }
std::vector<sf::IntRect> &Animation::getFrames(){ return frames; }
std::vector<sf::IntRect> &Animation::getInvertedFrames() { return frames_inverted; }

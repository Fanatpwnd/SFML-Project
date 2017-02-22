#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "Animation.h"

class AnimationManager{
	std::string currentAnimation;
	std::map<std::string, Animation> animations;
public:
	void createAnimation(std::string name, sf::Texture texture, float x, float y, float width, float height, float spped,int framesCount, float step);
	void setAnimation(std::string name);
	void invertAnimation(bool flag);
	void playAnimation();
	void pauseAnimation();
	void tick(float time);
	void draw(sf::RenderWindow &window, int x = 0,int y = 0);

	std::map<std::string, Animation> &getAnimations();
};
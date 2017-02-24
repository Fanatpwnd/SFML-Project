#include <SFML/Graphics.hpp>
#include <map>
#include "AnimationManager.h"
#include "Animation.h"
#include <iterator>

void AnimationManager::createAnimation(std::string name, sf::Texture texture, float x, float y, float width, float height, float step,int framesCount, float speed){

	animations[name] = Animation(texture, x, y, width, height, speed, framesCount, step);
	currentAnimation = name;
}

void AnimationManager::setAnimation(std::string name){ currentAnimation = name; }

void AnimationManager::draw(sf::RenderWindow *window, int x, int y){
	animations[currentAnimation].getSprite().setPosition(x, y);
	window->draw(animations[currentAnimation].getSprite());
}

void AnimationManager::invertAnimation(bool flag){ animations[currentAnimation].isInverted = flag; }
void AnimationManager::playAnimation(){ animations[currentAnimation].isPlaying = true; }
void AnimationManager::pauseAnimation(){ animations[currentAnimation].isPlaying = false; }
void AnimationManager::tick(float time){ animations[currentAnimation].tick(time); }
std::map<std::string, Animation> &AnimationManager::getAnimations(){ return animations; }


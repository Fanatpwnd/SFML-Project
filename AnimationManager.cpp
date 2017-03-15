#include "AnimationManager.h"

AnimationManager::AnimationManager(sf::Sprite* sprite) : m_ptrSprite(sprite){}

void AnimationManager::addAnimation(std::string nameAnimation){
	m_animations.insert(std::pair<std::string,Animation*>(nameAnimation, new Animation));
}

void AnimationManager::playAnimation(std::string nameAnimation, float time){
	m_ptrSprite->setTextureRect(m_animations.find(nameAnimation)->second->getCurrentFrame(time, 4));
}

void AnimationManager::initFrames(std::string nameAnimation, int x, int y, int width, int height,int framesCount, bool flag){
	if (!flag){
		for (int i = 0; i < framesCount; ++i){ m_animations.find(nameAnimation)->second->addFrame(i * x, y, width, height); }
	}
	else{
		for (int i = 1; i <= framesCount; ++i){ m_animations.find(nameAnimation)->second->addFrame(i * x, y, -width, height); }
	}
}

void AnimationManager::addFrame(std::string nameAnimation, int x, int y, int width, int height){
	m_animations.find(nameAnimation)->second->addFrame(x, y, width, height);
}
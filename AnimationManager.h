#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H
#include "Animation.h"
#include <map>

class AnimationManager{
	std::map<std::string, Animation*>	m_animations;
	sf::Sprite*							m_ptrSprite;

public:
	AnimationManager(){};
	AnimationManager(sf::Sprite*);

	void playAnimation(std::string nameAnimation, float time);
	void addAnimation(std::string nameAnimation);
	void initFrames(std::string nameAnimation, int x, int y, int width, int height, int framesCount, bool flag = 0);//flag - флаг, указывающий инвертированы 
																	//кадры анимации или нет (1 - инвертированы, 0 - нет)
	void addFrame(std::string nameAnimation, int x, int y, int width, int height);
};

#endif ANIMATION_MANAGER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

Animation :: Animation(){
	m_currentFrame = -1;
}

sf::IntRect Animation::getCurrentFrame(float time, float speed){ 
	m_currentFrame += time*speed;

	if (m_currentFrame > m_frames.size() - 1){ m_currentFrame = 0; }

	return m_frames[m_currentFrame];
}

void Animation::addFrame(int x, int y, int width, int height){
	m_frames.push_back(sf::IntRect(x, y, width, height));
}
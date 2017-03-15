#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include <vector>
/*It's the class animation
I think there is one type of animation. For example jump, run, shoot, etc.
*/
class Animation{
	
	std::vector<sf::IntRect>	m_frames;
	float						m_currentFrame;

public:

	Animation();

	sf::IntRect getCurrentFrame(float time, float speed);
	void addFrame(int x, int y, int width, int height);
};
#endif // ANIMATION_H


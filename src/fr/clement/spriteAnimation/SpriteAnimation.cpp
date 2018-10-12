#include "..//..//..//..//bin/fr/clement/spriteAnimation/SpriteAnimation.h"
#include<string>

SpriteAnimation::SpriteAnimation()
{

}


SpriteAnimation::~SpriteAnimation()
{
	std::printf("destruction de spirte Animation\n");
}

void SpriteAnimation::increaseMouvement()
{
	if (this->mouvement != 4) {
		this->mouvement++;
	}
	else {
		this->mouvement = 1;
	}
}

void SpriteAnimation::changeDirection(const int direction)
{
	switch (direction)
	{
	default:
		break;
	}
}

int SpriteAnimation::getMouvement()
{
	
	return mouvement;
}

int SpriteAnimation::getDirection()
{
	return this->direction;
}



#include "..//..//..//..//bin/fr/clement/spriteAnimation/SpriteAnimation.h"


SpriteAnimation::SpriteAnimation()
{

}


SpriteAnimation::~SpriteAnimation()
{
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



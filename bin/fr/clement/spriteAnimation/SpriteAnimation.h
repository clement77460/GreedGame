#ifndef SPRITEANIMATION_H_
#define SPRITEANIMATION_H_
#pragma once

enum directions {
	down,
	left,
	right,
	up
};

class SpriteAnimation
{
public:
	SpriteAnimation();
	~SpriteAnimation();
	void increaseMouvement();
	void changeDirection(const int test);
	int getMouvement();
	int getDirection();

private:
	directions direction=down;
	int mouvement=1;
	
};

#endif
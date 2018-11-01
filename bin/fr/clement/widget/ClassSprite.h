#ifndef CLASSPRITE_H_
#define CLASSPRITE_H_
#pragma once

#include <SFML/graphics.hpp>
#include "..//..//..//..//bin/fr/clement/spriteAnimation/SpriteAnimation.h"

class ClassSprite 
{
	

public:
	ClassSprite();
	~ClassSprite();
	void loadTexture(const sf::Texture* texture);
	void draw(sf::RenderWindow &windows,int line,int col);
	void setLine(int line, int column);

	int getLine();
	int getColumn();

private:
	const int gapX = 32;
	const int gapY = 48;

	int line;
	int column;

	sf::Sprite sprite;
	SpriteAnimation* anim;
};

#endif


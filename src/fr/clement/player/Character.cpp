#include "../../../bin/fr/clement/player/Character.h"



Character::Character()
{
}


Character::~Character()
{
}

void Character::attributePlace(int line, int column)
{
	sprite.setLine(line, column);
}

void Character::initCharacter(std::string type)
{
	if (type == "war") {
		this->setSpriteTexture("..//image/sprites//war.png");
		this->setFrameTexture("..//image/sprites//warFrame.png");
	}
	else {
		this->setFrameTexture("..//image/sprites//mage.jpg");
	}
	sprite.loadTexture(&spriteTexture);

	
}

sf::Texture Character::getFrameTexture()
{
	return this->frameTexture;
}

ClassSprite* Character::getSprite()
{
	return &this->sprite;
}

void Character::setSpriteTexture(std::string path)
{
	if (!spriteTexture.loadFromFile(path)) {

	}
	spriteTexture.setSmooth(true);
}

void Character::setFrameTexture(std::string path)
{
	if (!frameTexture.loadFromFile(path)) {

	}
	frameTexture.setSmooth(true);
}

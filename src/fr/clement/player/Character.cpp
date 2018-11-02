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
	this->type = type;
	//caracteristic.initValues(100, 100, 100, 15, 5, 2);

	if (type == "war") {
		this->setSpriteTexture("..//image/sprites//war.png");
		this->setFrameTexture("..//image/sprites//warFrame.png");
		caracteristic.initValues(100, 100, 100, 15, 5, 2);
	}
	if(type =="mage")
	{
		this->setSpriteTexture("..//image/sprites//mage.png");
		this->setFrameTexture("..//image/sprites//mageFrame.png");
		caracteristic.initValues(100, 100, 100, 15, 5, 8);
	}
	if (type == "archer") {
		this->setSpriteTexture("..//image/sprites//archer.png");
		this->setFrameTexture("..//image/sprites//archerFrame.png");
		caracteristic.initValues(100, 100, 100, 15, 5, 10);
	}
	sprite.loadTexture(&spriteTexture);

	
}

std::string Character::getType()
{
	return this->type;
}

sf::Texture* Character::getFrameTexture()
{
	return &this->frameTexture;
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

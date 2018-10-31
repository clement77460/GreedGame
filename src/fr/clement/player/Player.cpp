#include "..\..\..\..\bin\fr\clement\player\Player.h"



Player::Player()
{

}


Player::~Player()
{
	std::printf("destructeur de player\n");
	delete[] character;
}

int Player::getNbSprite()
{
	return nbSprite;
}

int Player::getNbPlacement()
{
	return nbPlacement;
}

void Player::initAttributes(int number)
{
	this->nbPlacement = number;
	this->character = new Character[number];

}

void Player::increaseNbSprite()
{
	this->nbSprite++;
}

ClassSprite* Player::getCharacterSprite(int indice)
{
	return this->character[indice].getSprite();
}

sf::Texture Player::getCharacterFrameTexture(int indice)
{
	return this->character[indice].getFrameTexture();
}

Character* Player::getCharacter(int indice)
{
	return &this->character[indice];
}

Character* Player::getAllCharacters()
{
	Character* chars = new Character[2];
	for (int i = 0; i < 2; i++) {
		chars[i].initCharacter("mage"); //il faudrait juste init la frame 
	}
	return chars;
}

void Player::createNewSprite(int line, int column)
{

	this->character[nbSprite].initCharacter("war");
	this->character[nbSprite].attributePlace(line, column);

}

#include "..\..\..\..\bin\fr\clement\player\Player.h"
#include <iostream>


Player::Player()
{

}


Player::~Player()
{
	std::printf("destructeur de player\n");
	delete[] chars;
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

	//creation de tout ses characters
	this->chars = new Character[NbCharacters];
	
	chars[0].initCharacter("mage"); //il faudrait juste init la frame 
	chars[1].initCharacter("war"); //il faudrait juste init la frame 
	chars[2].initCharacter("archer"); //il faudrait juste init la frame 

}

void Player::increaseNbSprite()
{
	this->nbSprite++;
}

ClassSprite* Player::getCharacterSprite(int indice)
{
	return this->character[indice].getSprite();
}

sf::Texture* Player::getCharacterFrameTexture(int indice)
{
	return this->character[indice].getFrameTexture();
}

Character* Player::getCharacter(int indice)
{
	return &this->character[indice];
}

Character* Player::getSelectedCharacter()
{
	return &chars[charIndex];
}

void Player::nextCharacter()
{
	charIndex=((charIndex+1)% nbPlacement);
	std::cout << "accesing : " << charIndex;

}

void Player::previousCharacter()
{
	charIndex = charIndex - 1;
	if (charIndex < 0) {
		charIndex = NbCharacters - 1;
	}
	std::cout << "decr : " << charIndex;
}


void Player::createNewSprite(int line, int column)
{
	std::cout << this->chars[charIndex].getType() << "\n";
	this->character[nbSprite].initCharacter(this->chars[charIndex].getType());
	this->character[nbSprite].attributePlace(line, column);

}

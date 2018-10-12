#include "..\..\..\..\bin\fr\clement\player\Player.h"



Player::Player()
{

}


Player::~Player()
{
	std::printf("destructeur de player\n");
	delete[] sprite;
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
	this->sprite = new ClassSprite[number];

}

void Player::increaseNbSprite()
{
	this->nbSprite++;
}

ClassSprite* Player::getSprite(int indice)
{
	return &this->sprite[indice];
}

void Player::createNewSprite(int line, int column)
{
	sprite[nbSprite].setLine(line, column);
	sprite[nbSprite].loadTexture("..//image/sprites//war.png");
	std::printf("creation du sprite");
}

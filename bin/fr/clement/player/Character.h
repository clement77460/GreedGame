#pragma once
#include "../widget/ClassSprite.h" 
#include"Caracteristic.h"

class Character
{
public:
	Character();
	~Character();
	
	void attributePlace(int line, int column);
	void initCharacter(std::string type);

	std::string getType();
	sf::Texture* getFrameTexture();
	ClassSprite* getSprite();

	inline Caracteristic* getCarac() {
		return &this->caracteristic;
	}

private:

	void setSpriteTexture(std::string path);
	void setFrameTexture(std::string path);

	ClassSprite sprite;
	Caracteristic caracteristic;

	sf::Texture spriteTexture;
	sf::Texture frameTexture;
	std::string type;

	

};


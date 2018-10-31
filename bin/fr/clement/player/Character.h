#pragma once
#include "../widget/ClassSprite.h" 
class Character
{
public:
	Character();
	~Character();

	void attributePlace(int line, int column);
	void initCharacter(std::string type);
	sf::Texture getFrameTexture();
	ClassSprite* getSprite();

private:

	void setSpriteTexture(std::string path);
	void setFrameTexture(std::string path);

	ClassSprite sprite;
	sf::Texture spriteTexture;
	sf::Texture frameTexture;


	//METTRE UN OBJ CARACTERISTIQUE ICI

};


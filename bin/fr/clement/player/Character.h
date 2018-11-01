#pragma once
#include "../widget/ClassSprite.h" 
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

private:

	void setSpriteTexture(std::string path);
	void setFrameTexture(std::string path);

	ClassSprite sprite;
	sf::Texture spriteTexture;
	sf::Texture frameTexture;
	std::string type;

	//METTRE UN OBJ CARACTERISTIQUE ICI

};


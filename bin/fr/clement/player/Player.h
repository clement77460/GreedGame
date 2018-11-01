#ifndef PLAYER_H
#define PLAYER_H

#include"Character.h"


#define NbCharacters 3 //a modifier quand on aura la BD !!

class Player
{
public:
	Player();
	~Player();

	int getNbSprite();
	int getNbPlacement();

	void initAttributes(int number);
	void increaseNbSprite();
	ClassSprite* getCharacterSprite(int indice);
	sf::Texture* getCharacterFrameTexture(int indice);
	Character* getCharacter(int indice);
	Character* getSelectedCharacter();
	void nextCharacter();
	void previousCharacter();

	void createNewSprite(int line,int column);

private:
	int nbPlacement;
	int nbSprite = 0;
	
	Character* chars;
	int charIndex = 0;

	Character* character;

};


#endif

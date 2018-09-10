#ifndef PLAYER_H
#define PLAYER_H

#include "../widget/ClassSprite.h"

class Player
{
public:
	Player();
	~Player();

	int getNbSprite();
	int getNbPlacement();

	void initAttributes(int number);
	void increaseNbSprite();
	ClassSprite* getSprite(int indice);
	void createNewSprite(int line,int column);

private:
	int nbPlacement;
	int nbSprite = 0;
	
	ClassSprite* sprite;
};


#endif

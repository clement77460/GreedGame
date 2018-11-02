#include "..//..//../bin/fr/clement/player/Caracteristic.h"



Caracteristic::Caracteristic()
{
}


Caracteristic::~Caracteristic()
{
}

void Caracteristic::initValues(int hp, int mp, int ct, int atk, int def, int mvt)
{
	this->hp = hp;
	this->hpMax = hp;

	this->mp = mp;
	this->mpMax = mp;

	this->ct = ct;
	this->ctMax = ct;

	this->atk = atk;
	this->def = def;
	this->mvt = mvt;

}

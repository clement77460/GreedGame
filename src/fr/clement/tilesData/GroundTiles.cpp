#include "../../../../bin/fr/clement/tilesData/GroundTiles.h"
#include<string>


GroundTiles::GroundTiles()
{
}


GroundTiles::~GroundTiles()
{
}

bool GroundTiles::isAvailable() const
{
	if (hasSomeone)
		return false;
	if (!isMovable)
		return false;
	return true;
}

void GroundTiles::toString()
{
	std::printf("JE SUIS UN GROUND AVEC %d SUR MOI\n",this->hasSomeone);
}



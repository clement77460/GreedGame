#include "../../../../bin/fr/clement/tilesData/WallTiles.h"
#include<string>


WallTiles::WallTiles()
{
}


WallTiles::~WallTiles()
{
}

bool WallTiles::isAvailable() const
{
	return false;
}


void WallTiles::toString()
{
	std::printf("JE SUIS UN WALL AVEC %d SUR MOI\n", this->hasSomeone);
}

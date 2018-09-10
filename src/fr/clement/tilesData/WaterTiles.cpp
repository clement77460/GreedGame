#include "../../../../bin/fr/clement/tilesData/WaterTiles.h"
#include<string>


WaterTiles::WaterTiles()
{
}


WaterTiles::~WaterTiles()
{
}

bool WaterTiles::isAvailable() const
{
	return false;
}

void WaterTiles::toString()
{
	std::printf("JE SUIS UN WATER AVEC %d SUR MOI\n", this->hasSomeone);
}

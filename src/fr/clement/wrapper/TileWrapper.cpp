#include "..\..\..\..\bin\fr\clement\wrapper\TileWrapper.h"
#include"../../../../bin/fr/clement/tilesData/WaterTiles.h"
#include"../../../../bin/fr/clement/tilesData/GroundTiles.h"
#include"../../../../bin/fr/clement/tilesData/WallTiles.h"
#include<string>

TileWrapper::TileWrapper()
{

}

TileWrapper::~TileWrapper()
{
	std::printf("destruction de TileWrapper");
}

TilesInterface * TileWrapper::getTileType()
{
	return this->tileType;
}

void TileWrapper::setTileType(int type)
{
	switch (type)
	{
	case 0:
		tileType = new WallTiles();
		break;
	case 1:
		tileType = new GroundTiles();
		break;
	case 3:
		tileType = new WaterTiles();
		break;
	default:
		break;
	}


}

void TileWrapper::setCoords(int line, int column)
{
	coords.setLine(line+1);
	coords.setColumn(column+1);
}

Coordinates TileWrapper::getCoords()
{
	return this->coords;
}

int TileWrapper::getLine()
{
	return this->coords.getLine();
}

int TileWrapper::getColumn()
{
	return this->coords.getColumn();
}

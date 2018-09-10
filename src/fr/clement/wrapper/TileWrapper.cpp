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
	this->line = line+1;
	this->column = column+1;
}

int TileWrapper::getLine()
{
	return this->line;
}

int TileWrapper::getColumn()
{
	return this->column;
}

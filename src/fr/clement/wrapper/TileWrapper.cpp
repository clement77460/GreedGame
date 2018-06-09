#include "..\..\..\..\bin\fr\clement\wrapper\TileWrapper.h"
#include"../../../../bin/fr/clement/tilesData/WaterTiles.h"
#include<string>

TileWrapper::TileWrapper()
{

}

TileWrapper::~TileWrapper()
{
	std::printf("destruction de TileWrapper");
}

void TileWrapper::setTileType(int type)
{
	

	TilesInterface* t;
	t=new WaterTiles();
	t->isAvailable();


}

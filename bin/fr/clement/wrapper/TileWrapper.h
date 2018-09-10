#ifndef TILEWRAPPER_H_
#define TILEWRAPPER_H_
#pragma once
#include"../tilesData/TilesInterface.h"
#include<SFML/Graphics.hpp>

class TileWrapper:public sf::RectangleShape
{
public:
	TileWrapper();
	~TileWrapper();
	TilesInterface* getTileType();
	void setTileType(int type);

	void setCoords(int line, int column);
	int getLine();
	int getColumn();

private:
	TilesInterface* tileType;
	int line;
	int column;
};

#endif


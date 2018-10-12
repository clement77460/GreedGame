#ifndef TILEWRAPPER_H_
#define TILEWRAPPER_H_
#pragma once
#include"../tilesData/TilesInterface.h"
#include<SFML/Graphics.hpp>
#include"../tilesData/Coordinates.h"

class TileWrapper:public sf::RectangleShape
{
public:
	TileWrapper();
	~TileWrapper();
	TilesInterface* getTileType();
	void setTileType(int type);
	void setCoords(int line, int column);
	Coordinates getCoords();
	int getLine();
	int getColumn();


private:
	TilesInterface* tileType;
	Coordinates coords;
};

#endif


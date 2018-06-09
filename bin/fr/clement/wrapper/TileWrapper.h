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

	void setTileType(int type);

private:

};

#endif


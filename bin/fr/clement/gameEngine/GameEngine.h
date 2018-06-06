#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#pragma once

#include"../wrapper/TileWrapper.h"


class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	void launchGraphicEngine();
	TileWrapper** getTiles();

private:
	
	TileWrapper** tiles=NULL;
	std::string data;
	
	
	
	int nbXTiles = 5;
	int nbYTiles = 8;
};
#endif


#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#pragma once

#include"../graphicEngine/GraphicEngine.h"

class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	

private:
	GraphicEngine * ge=NULL;
	TileWrapper** tiles=NULL;
	Controller controller;

	void launchGraphicEngine();
	
	const int nbXTiles = 5;
	const int nbYTiles = 8;
};
#endif


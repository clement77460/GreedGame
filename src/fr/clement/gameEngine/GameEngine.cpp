#include "..\..\..\..\bin\fr\clement\gameEngine\GameEngine.h"


GameEngine::GameEngine()
{
		
	this->ge = new GraphicEngine();
	this->launchGraphicEngine();
}

GameEngine::~GameEngine()
{
	
	for (int i = 0; i < 5; i++) {
		delete[] tiles[i];
	}
	delete[] tiles;
	delete ge;
}

void GameEngine::launchGraphicEngine()
{
	this->tiles = new TileWrapper*[nbXTiles];
	for (int i = 0; i < 5; i++) {
		this->tiles[i] = new TileWrapper[nbYTiles];
	}

	

	ge->createMap(this->tiles);
	ge->gameLoop(controller);
}

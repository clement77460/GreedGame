#include "..\..\..\..\bin\fr\clement\gameEngine\GameEngine.h"
#include <string>

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
	delete[] tiles;
}

void GameEngine::launchGraphicEngine()
{
	this->tiles = new TileWrapper*[nbXTiles];
	for (int i = 0; i < 5; i++) {
		this->tiles[i] = new TileWrapper[nbYTiles];
		this->tiles[i]->setPosition(0, 0);
	}
}

TileWrapper ** GameEngine::getTiles()
{
	return this->tiles;
}

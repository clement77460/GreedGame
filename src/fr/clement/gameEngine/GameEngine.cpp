#include "..\..\..\..\bin\fr\clement\gameEngine\GameEngine.h"


GameEngine::GameEngine()
{
	this->ge = new GraphicEngine();
	this->launchGraphicEngine();
}

GameEngine::~GameEngine()
{
}

void GameEngine::launchGraphicEngine()
{
	ge->gameLoop();
}

#include "../../../..//bin/fr/clement/controller/Controller.h"

Controller::Controller(const GameEngine & gameEngine, const GraphicEngine & graphicEngine)
{
	this->gameEngine = gameEngine;
	this->graphicEngine = graphicEngine;
}

void Controller::onLoad()
{
	gameEngine.launchGraphicEngine();
	graphicEngine.createMap(gameEngine.getTiles());
	graphicEngine.gameLoop();
}


Controller::~Controller()
{
	
}

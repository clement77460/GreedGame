#include "../../../..//bin/fr/clement/controller/Controller.h"
#include<iostream>
Controller::Controller(GameEngine*  gameEngine,GraphicEngine* graphicEngine)
{
	this->gameEngine = gameEngine;
	this->graphicEngine = graphicEngine;
}

void Controller::onLoad()
{
	
	gameEngine->setControllerAndView(this , graphicEngine);
	graphicEngine->setController(this);

	gameEngine->initWidgets();
	
	while (gameEngine->getNbSprite() < gameEngine->getNbPlacement()) {
		gameEngine->startPlacementState();
	}
	gameEngine->startGameState();
}

bool Controller::onPlacementClick(int x,int y,std::string selectedSprite)
{
	std::printf("click de souris en x:%d et y:%d, sprite selected : ", x, y);
	std::cout << selectedSprite << std::endl;

	return gameEngine->checkPlacementPosition(x, y, selectedSprite);
}

void Controller::timeToUpdate()
{
	sf::Time elapsed = clock.getElapsedTime();
	if (elapsed.asMilliseconds() > 200) { //ToDO ((1/fps)*1000) 
		gameEngine->updateGraphicEngine();
		clock.restart();
	}
}


Controller::~Controller()
{
	std::printf("destructeur de controller\n");
	
}

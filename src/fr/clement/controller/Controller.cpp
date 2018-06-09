#include "../../../..//bin/fr/clement/controller/Controller.h"

Controller::Controller(GameEngine*  gameEngine,GraphicEngine* graphicEngine)
{
	this->gameEngine = gameEngine;
	this->graphicEngine = graphicEngine;
}

void Controller::onLoad()
{
	
	gameEngine->setControllerAndView(this , graphicEngine);
	graphicEngine->setController(this);


	gameEngine->initTileWrapper();
	gameEngine->initWidgets();
	gameEngine->startGraphicEngine();


}

void Controller::onClick(int x,int y)
{
	printf("click de souris en x:%d et y:%d \n", x, y);
	gameEngine->getTileClicked(x,y);
}


Controller::~Controller()
{
	std::printf("destructeur de controller\n");
	
}

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

void Controller::createDownFrame(UnitFrame * unitFrame)
{
	unitFrame->loadImage();
	unitFrame->initFrame();

	this->updateDownFrame(unitFrame, gameEngine->getActualPlayer()->getSelectedCharacter());
}

bool Controller::onPlacementClick(int x,int y)
{

	if (this->isArrowClicked(x, y)) {
		gameEngine->updateGraphicEngine();
		return false;
	}

	if(y<500)
		return gameEngine->checkPlacementPosition(x, y);
	
	return false;
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

bool Controller::isArrowClicked(int x, int y)
{
	UnitFrame* unitFrame = gameEngine->getUnitFrame();
	sf::RectangleShape *arrow = unitFrame->getArrows();

	if (arrow[0].getGlobalBounds().contains(x, y)) {
		Player* actualPlayer=gameEngine->getActualPlayer();
		actualPlayer->previousCharacter();

		this->updateDownFrame(unitFrame, actualPlayer->getSelectedCharacter());
		return true;
	}
	if (arrow[1].getGlobalBounds().contains(x, y)) {
		Player* actualPlayer = gameEngine->getActualPlayer();
		actualPlayer->nextCharacter();

		this->updateDownFrame(unitFrame,actualPlayer->getSelectedCharacter());
		return true;
	}

	return false;
}

void Controller::updateDownFrame(UnitFrame* unitFrame,Character * character)
{
	unitFrame->setTextureImage(character->getFrameTexture());
	unitFrame->changeCharInformations(character->getCarac());
	unitFrame->mapToTextVector();
}


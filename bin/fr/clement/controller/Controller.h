#ifndef CONTROLLER_H
#define CONTROLLER_H
#pragma once

#include"../graphicEngine/GraphicEngine.h"
#include"../gameEngine/GameEngine.h"
class Controller
{
public:
	Controller(GameEngine* gameEngine, GraphicEngine* graphicEngine);
	void onLoad();
	bool onClick(int x, int y,std::string selectedSprite);
	bool onPlacementClick(int x, int y);
	void timeToUpdate();
	~Controller();
	
private :

	bool isArrowClicked(int x, int y);

	GameEngine* gameEngine=NULL;
	GraphicEngine* graphicEngine=NULL;
	sf::Clock clock;
};


#endif 

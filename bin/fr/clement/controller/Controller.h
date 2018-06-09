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
	void onClick(int x, int y);
	~Controller();
	
private :
	GameEngine* gameEngine=NULL;
	GraphicEngine* graphicEngine=NULL;
};


#endif 

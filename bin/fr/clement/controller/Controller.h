#ifndef CONTROLLER_H
#define CONTROLLER_H
#pragma once

#include"../graphicEngine/GraphicEngine.h"

class Controller
{
public:
	Controller(const GameEngine &gameEngine,const GraphicEngine &graphicEngine);
	void onLoad();
	~Controller();
	
private :
	GameEngine gameEngine;
	GraphicEngine graphicEngine;
};


#endif 

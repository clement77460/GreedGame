#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#pragma once

#include"../wrapper/TileWrapper.h"
class GraphicEngine;
class Controller;
class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	void setControllerAndView(Controller *controller,GraphicEngine *graphicEngine);
	void initTileWrapper();
	void initWidgets();
	void startGraphicEngine();
	void getTileClicked(int x,int y);

private:
	
	TileWrapper** tiles=NULL;
	Controller* controller=NULL;
	GraphicEngine* graphicEngine = NULL;
	ClassSprite* sprite = NULL;
	TileMap map;

	int nbXTiles = 5;
	int nbYTiles = 8;

	void createMap();
	void createSprite();
};
#endif


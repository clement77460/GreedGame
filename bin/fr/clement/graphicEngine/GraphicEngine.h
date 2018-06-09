#ifndef GRAPHICENGINE_H_
#define GRAPHICENGINE_H_
#pragma once

#include"../widget/TileMap.h"
#include<SFML/Graphics.hpp>
#include"../widget/ClassSprite.h"


class Controller;
class GraphicEngine
{
public:
	GraphicEngine();
	~GraphicEngine();
	void gameLoop(TileMap* map,ClassSprite* sprite);
	void setController(Controller* controller);

private:
	sf::Clock clock;
	sf::RenderWindow* window=NULL;
	Controller* controller;
	int fps = 5; //5 images par secondes
	
	void updateEngine(TileMap* map, ClassSprite* sprite);
};

#endif
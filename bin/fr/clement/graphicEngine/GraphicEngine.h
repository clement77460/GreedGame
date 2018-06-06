#ifndef GRAPHICENGINE_H_
#define GRAPHICENGINE_H_
#pragma once

#include"../widget/TileMap.h"
#include"../gameEngine/GameEngine.h"
#include<SFML/Graphics.hpp>
#include"../widget/ClassSprite.h"


class Controller;
class GraphicEngine
{
public:
	GraphicEngine(const GameEngine &gameEngine0);
	GraphicEngine();
	~GraphicEngine();
	void gameLoop();
	void createMap(TileWrapper** tiles);

private:
	sf::Clock clock;
	sf::RenderWindow* window=NULL;
	Controller* c;
	int fps = 5; //5 images par secondes
	ClassSprite* sprite = NULL;
	TileMap map;
	GameEngine gameEngine;

	void createSprite();
	void updateEngine();
};

#endif
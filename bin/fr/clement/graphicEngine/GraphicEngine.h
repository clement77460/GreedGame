#ifndef GRAPHICENGINE_H_
#define GRAPHICENGINE_H_
#pragma once

#include<SFML/Graphics.hpp>

#include"../widget/ClassSprite.h"
#include"../widget/TileMap.h"
#include"../gameEngine/GameEngine.h"
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

	int fps = 5; //5 images par secondes
	ClassSprite* sprite = NULL;
	TileMap map;
	GameEngine gameEngine;

	void createSprite();
	void updateEngine();
};

#endif
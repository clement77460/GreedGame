#ifndef GRAPHICENGINE_H_
#define GRAPHICENGINE_H_
#pragma once

#include<SFML/Graphics.hpp>

#include"../widget/ClassSprite.h"
#include"../controller/Controller.h"
#include"../widget/TileMap.h"

class GraphicEngine
{
public:
	GraphicEngine();
	~GraphicEngine();
	void gameLoop(Controller controller);
	void createMap(TileWrapper** tiles);

private:
	const int fps = 5; //5 images par secondes
	sf::Clock clock;
	sf::RenderWindow* window=NULL;
	TileMap map;
	ClassSprite* sprite=NULL;

	void createSprite();
	void updateEngine();
};

#endif
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
	void gameLoop();
	void placementLoop();
	void setController(Controller* controller);
	void updateSprites(ClassSprite* sprite, int line, int column);
	void updateDrawable(sf::Drawable* t);
	void clearWindow();
	void displayWindow();
	void testThread(int nombre);
	//le thread ne fonctionne pas pour les fonctions surchargées


private:
	sf::RenderWindow* window=NULL;
	Controller* controller;

	
	
};

#endif
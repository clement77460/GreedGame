#include"../../../../bin/fr/clement/controller/Controller.h" //evite la dépendance circulaire 
#include"../../../../bin/fr/clement/graphicEngine/GraphicEngine.h"
#include "..\..\..\..\bin\fr\clement\gameEngine\GameEngine.h"
#include <string>


GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
	std::printf("destructeur de gameEngine\n");
	/*for (int i = 0; i < 5; i++) {
		delete tiles[i];
	}*/
	delete[] tiles;
	delete sprite;
}

void GameEngine::setControllerAndView(Controller *controller, GraphicEngine *graphicEngine)
{
	this->controller = controller;
	this->graphicEngine = graphicEngine;
}

void GameEngine::initTileWrapper()
{
	
	this->tiles = new TileWrapper*[nbXTiles];
	for (int i = 0; i < 5; i++) {
		this->tiles[i] = new TileWrapper[nbYTiles];
		this->tiles[i]->setPosition(0, 0);
	}

}

void GameEngine::initWidgets()
{
	this->createMap();
	this->createSprite();

}

void GameEngine::startGraphicEngine()
{
	this->graphicEngine->gameLoop(&this->map,this->sprite);
}

void GameEngine::getTileClicked(int x, int y)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->tiles[i][j].getGlobalBounds().contains(sf::Vector2f(x, y))) {
				std::printf("la ligne %d et colonne %d \n", i, j);
			}
		}
	}
}



void GameEngine::createMap()
{
	//Permet de définir les tuiles

	int level[]{
		0,1,1,3,3,3,1,0,
		0,1,1,3,3,3,1,0,
		0,1,1,3,3,3,1,0,
		0,1,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0
	};
	map.loadTiles("..//image//textureSet.jpg", sf::Vector2u(100, 100), level, 8, 5, tiles);

}

void GameEngine::createSprite()
{
	this->sprite = new ClassSprite();
	sprite->loadTexture("..//image/sprites//war.png");
	std::printf("creation du sprite");
}

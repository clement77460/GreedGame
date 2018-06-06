#include"../../../../bin/fr/clement/controller/Controller.h"//en premier pour la dépendance cyclique !!
#include "..//..//..//..//bin/fr/clement/graphicEngine/GraphicEngine.h"


GraphicEngine::GraphicEngine(const GameEngine &gameEngine)
{ 
	this->gameEngine = gameEngine;
	this->window = new sf::RenderWindow(sf::VideoMode(800, 500), "GreedGame");
	this->createSprite();
}
GraphicEngine::GraphicEngine()
{
}

GraphicEngine::~GraphicEngine()
{
	//delete window;
	//delete sprite;
}

void GraphicEngine::gameLoop()
{
	while (this->window->isOpen())
	{
		sf::Event controller;
		while (window->pollEvent(controller))
		{
			
			if (controller.type == sf::Event::Closed)
				this->window->close();
			

			
		}
		this->updateEngine();
		
		
	}
}


void GraphicEngine::updateEngine() {

	sf::Time elapsed = clock.getElapsedTime();
	if (elapsed.asMilliseconds() >200 ) { //ToDO ((1/fps)*1000) 
		clock.restart();
		window->clear();
		window->draw(map);
		sprite->draw(*window, 1, 2);
		window->display();
	}
}

void GraphicEngine::createSprite()
{
		
	this->sprite = new ClassSprite();
	sprite->loadTexture("..//image/sprites//war.png");
	std::printf("creation du sprite");
}

void GraphicEngine::createMap(TileWrapper** tiles)
{
	//Permet de définir les tuiles
	
	int level[]{
		0,1,1,3,3,3,1,0,
		0,1,1,3,3,3,1,0,
		0,1,1,3,3,3,1,0,
		0,1,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0
	};
	map.loadTiles("..//image//textureSet.jpg", sf::Vector2u(100, 100), level, 8, 5,tiles);

}

#include "..//..//..//..//bin/fr/clement/gameEngine/GameEngine.h"

GameEngine::GameEngine()
{
	this->window=new RenderWindow(sf::VideoMode(800, 500), "GreedGame");
	this->createMap();
	this->createSprite();
}


GameEngine::~GameEngine()
{
}

void GameEngine::gameLoop()
{
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();

			
		}
		this->updateEngine();
		
		
	}
}


void GameEngine::updateEngine() {

	sf::Time elapsed = clock.getElapsedTime();
	if (elapsed.asMilliseconds() >200 ) { //ToDO ((1/fps)*1000) 
		clock.restart();
		window->clear();
		window->draw(map);
		sprite->draw(*window, 1, 2);
		window->display();
	}
}

void GameEngine::createSprite()
{
	
	this->sprite = new ClassSprite();
	sprite->loadTexture("..//image/sprites//war.png");
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
	map.loadTiles("..//image//textureSet.jpg", Vector2u(100, 100), level, 8, 5);


}

#include"../../../../bin/fr/clement/controller/Controller.h"//en premier pour la dépendance cyclique !!
#include "..//..//..//..//bin/fr/clement/graphicEngine/GraphicEngine.h"



GraphicEngine::GraphicEngine()
{
	
	this->window = new sf::RenderWindow(sf::VideoMode(800, 500), "GreedGame");

}

GraphicEngine::~GraphicEngine()
{
	std::printf("destructeur de graphic engine\n************************");
	delete window;
	
}

void GraphicEngine::gameLoop(TileMap* map, ClassSprite* sprite)
{
	while (this->window->isOpen())
	{
		sf::Event ev;
		while (window->pollEvent(ev))
		{
			
			if (ev.type == sf::Event::Closed)
				this->window->close();
			if (ev.type == sf::Event::MouseButtonPressed) {
				if (ev.mouseButton.button == sf::Mouse::Left)
					controller->onClick(ev.mouseButton.x, ev.mouseButton.y);
			}
				
		}
		this->updateEngine(map,sprite);
		
		
	}
}


void GraphicEngine::updateEngine(TileMap* map, ClassSprite* sprite) {

	sf::Time elapsed = clock.getElapsedTime();
	if (elapsed.asMilliseconds() >200 ) { //ToDO ((1/fps)*1000) 
		clock.restart();
		window->clear();
		window->draw(*map);
		sprite->draw(*window, 1, 2);
		window->display();
	}
}



void GraphicEngine::setController(Controller * controller)
{
	this->controller = controller;
}

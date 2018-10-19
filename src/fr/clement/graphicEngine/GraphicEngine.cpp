#include"../../../../bin/fr/clement/controller/Controller.h"//en premier pour la dépendance cyclique !!
#include "..//..//..//..//bin/fr/clement/graphicEngine/GraphicEngine.h"



GraphicEngine::GraphicEngine()
{
	//800-500
	this->window = new sf::RenderWindow(sf::VideoMode(800, 700), "GreedGame");
	this->window->setPosition(sf::Vector2i(0, 0));

}

GraphicEngine::~GraphicEngine()
{
	std::printf("destructeur de graphic engine\n************************");
	delete window;
	
}

void GraphicEngine::gameLoop()
{
	
	while (this->window->isOpen())
	{
		sf::Event ev;
		while (window->pollEvent(ev))
		{
			
			if (ev.type == sf::Event::Closed)
				this->window->close();
			if (ev.type == sf::Event::MouseButtonPressed) {
				if (ev.mouseButton.button == sf::Mouse::Left) {
					//controller->onClick(ev.mouseButton.x, ev.mouseButton.y, "war");
					//recuperer le nom du sprite sur un label rectangle en bas !
				}
			}
				
		}
		controller->timeToUpdate();
		
		
	}
}

void GraphicEngine::placementLoop()
{
	bool placementAccepted = false;
	while (this->window->isOpen() && !placementAccepted)
	{
		sf::Event ev;
		while (window->pollEvent(ev))
		{

			if (ev.type == sf::Event::Closed)
				this->window->close();
			if (ev.type == sf::Event::MouseButtonPressed) {
				if (ev.mouseButton.button == sf::Mouse::Left) {
					placementAccepted = controller->onPlacementClick(ev.mouseButton.x, ev.mouseButton.y, "war");
				}
			}

		}


	}
}


void GraphicEngine::updateSprites(ClassSprite* sprite, int line, int column) {

	sprite->draw(*window, line, column);
}

void GraphicEngine::updateDrawable(sf::Drawable * t)
{
	UnitFrame uf;
	uf.loadImage();
	uf.initFrame();
	window->draw(uf);
	window->draw(*t);
	
}

void GraphicEngine::clearWindow()
{
	window->clear();
}

void GraphicEngine::displayWindow()
{
	window->display();
}





void GraphicEngine::setController(Controller * controller)
{
	this->controller = controller;
}

void GraphicEngine::testThread(int nombre)
{
	std::printf("Thread");
}




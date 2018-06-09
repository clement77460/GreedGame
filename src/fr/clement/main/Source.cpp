#include"..//..//..//..//bin/fr/clement/controller/Controller.h"

int main()
{
	
	GameEngine ge;
	GraphicEngine graphicEngine;

	Controller controller(&ge, &graphicEngine);
	controller.onLoad();


	return 0;
}
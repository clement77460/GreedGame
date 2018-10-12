#include"..//..//..//..//bin/fr/clement/controller/Controller.h"

int main()
{

	GameEngine ge(2);
	GraphicEngine graphicEngine;

	Controller controller(&ge, &graphicEngine);
	controller.onLoad();
	

	return 0;
}
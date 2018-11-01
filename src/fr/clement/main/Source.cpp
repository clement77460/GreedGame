#include"..//..//..//..//bin/fr/clement/controller/Controller.h"
//#include"..//..//..//..//bin/fr/clement/utility/PersonnalMap.h"

int main()
{


	system("pause");
	GameEngine ge(1);
	GraphicEngine graphicEngine;

	Controller controller(&ge, &graphicEngine);
	controller.onLoad();

	return 0;

	
}

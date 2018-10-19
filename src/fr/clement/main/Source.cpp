#include"..//..//..//..//bin/fr/clement/controller/Controller.h"
#include"..//..//..//..//bin/fr/clement/utility/PersonnalMap.h"
int main()
{

	
	PersonnalMap<int, std::string> pm ;
	pm.add(5,"first");
	pm.add(6, "second");
	pm.add(7, "four");
	pm.add(5, "thrid");
	pm.toString();
	system("pause");
	/*GameEngine ge(2);
	GraphicEngine graphicEngine;

	Controller controller(&ge, &graphicEngine);
	controller.onLoad();*/
	

	return 0;
}
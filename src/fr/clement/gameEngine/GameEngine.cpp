#include"../../../../bin/fr/clement/controller/Controller.h" //evite la dépendance circulaire 
#include"../../../../bin/fr/clement/graphicEngine/GraphicEngine.h"
#include "..\..\..\..\bin\fr\clement\gameEngine\GameEngine.h"

#include <string>
#include<thread>



GameEngine::GameEngine(int nbPlayers)
{
	player = new Player[nbPlayers];


	for (int i = 0; i < 2; i++) {
		player[i].initAttributes(4); // 4 = nb de personnages du joueur 
		std::printf("nb sprites = %d\n",player[i].getNbPlacement());
	}

}

GameEngine::~GameEngine()
{
	std::printf("destructeur de gameEngine\n");
	/*for (int i = 0; i < 5; i++) {
		delete tiles[i];
	}*/
	delete[] tiles;
	delete[] player;
}

void GameEngine::setControllerAndView(Controller *controller, GraphicEngine *graphicEngine)
{
	this->controller = controller;
	this->graphicEngine = graphicEngine;
}

void GameEngine::initWidgets()
{

	this->initTileWrapper();
	this->createMap();

	graphicEngine->updateDrawable(&map);
	graphicEngine->displayWindow();

	/*std::thread th(&GraphicEngine::testThread,graphicEngine,5);//argument int
	th.join();*/

}

void GameEngine::initTileWrapper()
{

	this->tiles = new TileWrapper*[nbXTiles];
	for (int i = 0; i < 5; i++) {
		this->tiles[i] = new TileWrapper[nbYTiles];
	}

}

void GameEngine::startPlacementState()
{
	
	this->calculatingMovableTiles();
	//Calculer les tiles dispo ici
	this->graphicEngine->placementLoop();
}

void GameEngine::startGameState()
{
	std::printf("grameloop\n");
	this->graphicEngine->gameLoop();
}

/*
Ajouter les composants graphique de la fenêtre
*/
void GameEngine::updateGraphicEngine()
{
	//faire une boucle de updateDrawable pour afficher les cases possible
	
	graphicEngine->clearWindow();
	graphicEngine->updateDrawable(&map);

	//refresh first player sprite
	for (int i = 0; i < player[0].getNbSprite(); i++) {
		ClassSprite* sprite = player[0].getSprite(i);
		graphicEngine->updateSprites(sprite, sprite->getLine(), sprite->getColumn());
	}

	//refresh second player sprite
	for (int i = 0; i < player[1].getNbSprite(); i++) {
		ClassSprite* sprite = player[1].getSprite(i);
		graphicEngine->updateSprites(sprite, sprite->getLine(), sprite->getColumn());
	}
	
	graphicEngine->displayWindow();
}

bool GameEngine::checkPlacementPosition(int x, int y, std::string selectedSprite,int indexPlayer)
{
	std::vector<Coordinates> indexToChange;

	TileWrapper tileToCheck=getTileClicked(x, y);
	if (tileToCheck.getTileType()->getIsMovable()) {

		tileToCheck.getTileType()->setSomeone(true);
		this->player[indexPlayer].createNewSprite(tileToCheck.getLine(),tileToCheck.getColumn());
		this->player[indexPlayer].increaseNbSprite();

		//on remet les cases en transparent puis on recolorie les disponibles
		for (int i = 0; i < nbXTiles; i++) {
			for (int j = 0; j < nbYTiles; j++) {
				indexToChange.push_back(Coordinates(i,j));
				tiles[i][j].getTileType()->setIsMovable(false);
			}
		}

		for (int i = 0; i < indexToChange.size(); i++)
		{
			map.displayingAvailableTiles(indexToChange[i], sf::Color(255, 255, 255,255));
		}

		// changement du joueur à placer / jouer
		if (player[indexPlayer].getNbPlacement() == player[indexPlayer].getNbSprite()) {
			this->changeTurn();
		}

		this->updateGraphicEngine();
		return true;
	}

	return false;
}

int GameEngine::getNbPlacement()
{
	return player[0].getNbPlacement()+ player[1].getNbPlacement(); //rajouter le nb de sprite du deuxieme joueur
}

int GameEngine::getNbSprite() {
	return player[0].getNbSprite()+ player[1].getNbSprite();
}

int GameEngine::getActualPlayer()
{
	return playerToPlay;
}

std::vector<Coordinates> GameEngine::calculatingMovableTiles()
{
	int ligneDepart = 0;
	int colDepart =0;
	int distance = 2;
	
	printf("calculating \n");
	std::vector<Coordinates> indexToChange;


	this->recursivityMove(indexToChange,distance,ligneDepart,colDepart);
	
	for (int i = 0; i < indexToChange.size(); i++)
	{
		map.displayingAvailableTiles(indexToChange[i],sf::Color(139,131,252,255));
	}

	this->updateGraphicEngine();

	return indexToChange;
}

void GameEngine::recursivityMove(std::vector<Coordinates>& indexToChange,int distanceLeft, int ligneDepart, int colDepart)
{
	if (distanceLeft < 0 || ligneDepart <0 || colDepart<0) {

	}
	else {
		Coordinates coord(ligneDepart, colDepart);

		int isPresent = 0;

		for (int i = 0; i < indexToChange.size(); i++) {
			if (coord == indexToChange[i]) {
				isPresent = 1;
			}
				
		}
		if (!isPresent) {
			if (tiles[ligneDepart][colDepart].getTileType()->isAvailable()) {
				indexToChange.push_back(coord);
				tiles[ligneDepart][colDepart].getTileType()->setIsMovable(true);
			}
		}

		recursivityMove(indexToChange, distanceLeft - 1,ligneDepart,colDepart+1);//deplacement a droite
		recursivityMove(indexToChange, distanceLeft - 1, ligneDepart, colDepart - 1);//deplacement a gauche
		recursivityMove(indexToChange, distanceLeft - 1, ligneDepart+1, colDepart );//deplacement en haut
		recursivityMove(indexToChange, distanceLeft - 1, ligneDepart-1, colDepart );//deplacement en bas

	}
}

TileWrapper GameEngine::getTileClicked(int x, int y)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->tiles[i][j].getGlobalBounds().contains(sf::Vector2f(x, y))) {
				std::printf("la ligne %d et colonne %d \n", i, j);
				this->tiles[i][j].getTileType()->toString();
				return this->tiles[i][j];
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

void GameEngine::changeTurn()
{
	playerToPlay = (playerToPlay + 1) % 2;
}



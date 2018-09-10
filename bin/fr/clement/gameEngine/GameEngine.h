#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include"../wrapper/TileWrapper.h"
#include"../player/Player.h"

enum gameState {
	placement,
	movement,
	attack,
	wait
};

class GraphicEngine;
class Controller;
class GameEngine
{
public:
	GameEngine(int nbPlayers);
	~GameEngine();
	void setControllerAndView(Controller *controller,GraphicEngine *graphicEngine);
	void initTileWrapper();
	void initWidgets();
	void startPlacementState();
	void startGameState();
	int* getAvailableTiles(int posDepart);
	TileWrapper getTileClicked(int x,int y);
	void updateGraphicEngine();
	bool checkPlacementPosition(int x,int y,std::string selectedSprite);
	int getNbPlacement();
	int getNbSprite();

private:
	
	TileWrapper** tiles=NULL;
	Controller* controller=NULL;
	GraphicEngine* graphicEngine = NULL;
	ClassSprite* sprite = NULL;
	Player* player = NULL;
	TileMap map;
	gameState state = placement;

	int nbXTiles = 5;
	int nbYTiles = 8;
	

	void createMap();
};
#endif


#include <SFML/Graphics.hpp>
#include "../../../../bin/fr/clement/widget/TileMap.h"
#include "../../../../bin/fr/clement/widget/ClassSprite.h"

class GraphicEngine
{
public:
	GraphicEngine();
	~GraphicEngine();
	void gameLoop();

private:
	const int fps = 5; //5 images par secondes
	sf::Clock clock;
	sf::RenderWindow* window;
	TileMap map;
	ClassSprite* sprite;

	void createSprite();
	void createMap();
	void updateEngine();
};


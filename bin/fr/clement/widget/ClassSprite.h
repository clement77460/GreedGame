#include <SFML/graphics.hpp>
#include "..//..//..//..//bin/fr/clement/spriteAnimation/SpriteAnimation.h"

using namespace sf;

class ClassSprite 
{
	

public:
	ClassSprite();
	~ClassSprite();
	void loadTexture(const std::string& tileset);
	void draw(sf::RenderWindow &windows,int line,int col);

private:
	const int gapX = 32;
	const int gapY = 48;
	sf::Texture spriteTexture;
	sf::Sprite sprite;
	SpriteAnimation* anim;
};


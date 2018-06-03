#include "..//..//..//..//bin/fr/clement/widget/ClassSprite.h"

/* Pour le sprite :
		Ecart en X : 32px
		Ecart en Y : 48px
*/
ClassSprite::ClassSprite()
{
	this->anim = new SpriteAnimation();
}


ClassSprite::~ClassSprite()
{
}

void ClassSprite::loadTexture(const std::string & spriteSet)
{
	if (!this->spriteTexture.loadFromFile(spriteSet)) {
		std::printf("not found");
	}
	spriteTexture.setSmooth(true);
	sprite.setTexture(spriteTexture);
	
	
	
}

void ClassSprite::draw(sf::RenderWindow &target,int line,int col)
{
	
	anim->increaseMouvement();
	sprite.setTextureRect(sf::IntRect((anim->getMouvement() - 1)*this->gapX, (anim->getDirection())*this->gapY
		, this->gapX,this->gapY));
	sprite.setPosition((100 * col) - 60, (100 * line) - 80);
	target.draw(sprite);	
	

}

#include "../../../../bin/fr/clement/widget/UnitFrame.h"

void UnitFrame::loadImage()
{
	if (!textureImage.loadFromFile("..//image/sprites//warFrame.png")) {
		
	}
	if (!backImage.loadFromFile("..//image/Fond//10_10.jpg")) {

	}
	if (!textureLogo.loadFromFile("..//image/Carac/image2.png")) {

	}
	
	if (!font.loadFromFile("..//image/arial.ttf"))
	{
		// error...
	}

	textureLogo.setSmooth(true);
	textureImage.setSmooth(true);
	backImage.setSmooth(true);
		
	
}

UnitFrame::UnitFrame()
{
}

UnitFrame::~UnitFrame()
{
}

void UnitFrame::initFrame() {
	this->buildingBackGround();

	this->buildingBars(220, 550, sf::Color(252, 60, 60), "hp");
	this->buildingBars(220, 600, sf::Color(65, 102, 249), "mp");
	this->buildingBars(220, 650, sf::Color(71, 249, 65), "ct");

	this->buildingLogo(450, 550, 0);
	this->buildingLogo(450, 600, 1);
	this->buildingLogo(450, 650, 2);

	this->buildingText(500, 550, "atk");
	this->buildingText(500, 600, "def");
	this->buildingText(500, 650, "mvt");
}

void UnitFrame::buildingBar(int positionStartX,int positionStartY,sf::Color color)
{
	sf::VertexArray vertex(sf::Quads, 4);
	vertex[0].position = sf::Vector2f(positionStartX + 10, positionStartY);
	vertex[1].position = sf::Vector2f(positionStartX, positionStartY+5);
	vertex[2].position = sf::Vector2f(positionStartX + 100, positionStartY+5);
	vertex[3].position = sf::Vector2f(positionStartX + 100 + 10, positionStartY);

	
	vertex[0].color = color;
	vertex[1].color = color;
	vertex[2].color = color;
	vertex[3].color = color;

	rects.push_back(vertex);
}

void UnitFrame::buildingLogo(int positionStartX, int positionStartY, int indice)
{
	sf::RectangleShape temp;
	sf::Color whitePixel(255, 255, 255, 255);


	temp.setTexture(&textureLogo);
	temp.setTextureRect(sf::IntRect(200*indice,0,200,160));
	temp.setSize(sf::Vector2f(35, 35));
	temp.setPosition(positionStartX, positionStartY);

	logos.push_back(temp);
	
}

void UnitFrame::buildingBackGround() {
	unitImage.setSize(sf::Vector2f(200, 200));
	unitImage.setPosition(0, 500);
	unitImage.setTexture(&textureImage);


	backGround.setFillColor(sf::Color(255, 255, 255, 128));
	backGround.setSize(sf::Vector2f(800, 200));
	backGround.setPosition(0, 500);
	backGround.setTexture(&backImage);
}

void UnitFrame::buildingText(int positionStartX, int positionStartY, std::string key)
{
	sf::Text text;

	text.setFont(font); 
	text.setCharacterSize(16);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(positionStartX, positionStartY));

	
}

void UnitFrame::buildingBars(int positionStartX, int positionStartY, sf::Color color, std::string barType)
{
	
	
	buildingText(positionStartX, positionStartY, barType);
	
	//decalage de 20 vers le bas
	positionStartY += 20;
	this->buildingBar(positionStartX, positionStartY, color);

	//decalage de 110 vers la droite
	positionStartX += 110;
	this->buildingText(positionStartX, positionStartY-5, barType);
	
	
}

void UnitFrame::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	

	target.draw(backGround, states);
	target.draw(unitImage, states);

	
	target.draw(rects[0],states);
	target.draw(rects[1], states);
	target.draw(rects[2], states);

	target.draw(logos[0], states);
	target.draw(logos[1], states);
	target.draw(logos[2], states);

	
}

void UnitFrame::changingCharCarac(std::string key, int value)
{

}

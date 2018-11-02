#pragma once
#include"../utility/PersonnalMap.h"
#include"../player/Caracteristic.h"
#include<SFML/Graphics.hpp>

class UnitFrame :public sf::Drawable, public sf::Transformable
{
public:
	void loadImage();
	void initFrame();
	void changeCharInformations(Caracteristic* carc);
	void mapToTextVector();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void setTextureImage(sf::Texture* texture);
	sf::RectangleShape* getArrows();

	UnitFrame();
	~UnitFrame();

private:
	void changingBarCarac(std::string barType, std::string actualValue, std::string maxValue);
	void changingSingleCarac(std::string type, std::string value);
	void buildingBar(int positionStartX, int positionStartY,sf::Color color);
	void buildingLogo(int positionStartX, int positionStartY, int indice);
	void buildingBars(int positionStartX, int positionStartY, sf::Color color, std::string barType);
	void buildingText(int positionStartX, int positionStartY, std::string key);
	void buildingArrows();
	void buildingBackGround();

	void addingTextBar(std::string s, std::string delimiter);
	void addingTextLogo(std::string s, std::string delimiter);


	sf::RectangleShape unitImage;
	sf::RectangleShape backGround;
	sf::RectangleShape arrow[2];

	sf::Texture backImage;
	sf::Texture textureLogo;
	sf::Texture texureArrow;

	PersonnalMap<std::string, sf::Text> pm;
	std::vector<sf::Text> allTexts;

	std::vector<sf::VertexArray> rects;
	std::vector<sf::RectangleShape> logos;

	sf::Font font;
};




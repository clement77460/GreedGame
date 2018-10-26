#pragma once
#include"../utility/PersonnalMap.h"
#include<SFML/Graphics.hpp>

class UnitFrame :public sf::Drawable, public sf::Transformable
{
public:
	void loadImage();
	void initFrame();
	
	void changingBarCarac(std::string barType, std::string actualValue, std::string maxValue);
	void changingSingleCarac(std::string type, std::string value);
	void mapToTextVector();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	UnitFrame();
	~UnitFrame();

private:
	void buildingBar(int positionStartX, int positionStartY,sf::Color color);
	void buildingLogo(int positionStartX, int positionStartY, int indice);
	void buildingBars(int positionStartX, int positionStartY, sf::Color color, std::string barType);
	void buildingText(int positionStartX, int positionStartY, std::string key);
	void buildingBackGround();

	void addingTextBar(std::string s, std::string delimiter);
	void addingTextLogo(std::string s, std::string delimiter);

	sf::RectangleShape unitImage;
	sf::RectangleShape backGround;

	sf::Texture backImage;
	sf::Texture textureImage;
	sf::Texture textureLogo;
	
	std::vector<sf::Text> allTexts;

	std::vector<sf::VertexArray> rects;
	std::vector<sf::RectangleShape> logos;

	PersonnalMap<std::string, sf::Text> pm;
	

	sf::Font font;
};




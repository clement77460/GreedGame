#pragma once
#include<SFML/Graphics.hpp>

class UnitFrame :public sf::Drawable, public sf::Transformable
{
public:
	void loadImage();
	void initFrame();
	
	void changingCharCarac(std::string key,int value);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	UnitFrame();
	~UnitFrame();

private:
	void buildingBar(int positionStartX, int positionStartY,sf::Color color);
	void buildingLogo(int positionStartX, int positionStartY, int indice);
	void buildingBars(int positionStartX, int positionStartY, sf::Color color, std::string barType);
	void buildingText(int positionStartX, int positionStartY, std::string key);
	void buildingBackGround();

	sf::RectangleShape unitImage;
	sf::RectangleShape backGround;

	sf::Texture backImage;
	sf::Texture textureImage;
	sf::Texture textureLogo;
		

	std::vector<sf::VertexArray> rects;
	std::vector<sf::RectangleShape> logos;

	std::map<std::string, sf::Text> caracText;
	

	sf::Font font;
};


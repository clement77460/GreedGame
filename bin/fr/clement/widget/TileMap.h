#ifndef TILEMAP_H_
#define TILEMAP_H_
#pragma once

#include<SFML/Graphics.hpp>
#include"../../../../bin/fr/clement/wrapper/TileWrapper.h"

class TileMap:public sf::Drawable, public sf::Transformable
{
public:
	TileMap();
	~TileMap();
	void loadTiles(const std::string& tileset, sf::Vector2u tileSize, const int* tilesType, 
		unsigned int width, unsigned int height,TileWrapper** tiles);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void displayingAvailableTiles(Coordinates coords, sf::Color color);

	

private:
	
	void setTextureOnQuad(sf::Vertex * quad,int indice);
	void loadTexture(const std::string& tileset);
	void setUpQuad(sf::Vertex* quad, sf::Vector2u tileSize, const int tilesType,const int line, const int col,const int width);
	void setUpTiles(sf::Vector2u tileSize,const int tilesType, const int line, const int col, TileWrapper** tiles);
	void changingColor(sf::Vertex * quad, sf::Color color);
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	
};

#endif


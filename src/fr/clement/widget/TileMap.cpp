#include "../../../../bin/fr/clement/widget/TileMap.h"


TileMap::TileMap()
{
}

TileMap::~TileMap()
{
	
	std::printf("destructeur de TileMap\n");
}

void TileMap::loadTiles(const std::string& tileset, sf::Vector2u tileSize, const int* tilesType,
	unsigned int width, unsigned int height, TileWrapper** tiles)
{	

	this->loadTexture(tileset);

	// on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);
	
	
	for (unsigned int i = 0; i < width; ++i) {
		for (unsigned int j = 0; j < height; ++j) {

			this->setUpTiles(tileSize, tilesType[i + j * width],i,j,tiles);

			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];
			this->setUpQuad(quad, tileSize, tilesType[i + j * width], i, j, width);
			
		}
	}
	
}

void TileMap::setTextureOnQuad(sf::Vertex *quad,int indice) {
	switch (indice)
	{
	case 0:
		quad[0].texCoords = sf::Vector2f(2, 2);
		quad[1].texCoords = sf::Vector2f(40, 2);
		quad[2].texCoords = sf::Vector2f(40, 40);
		quad[3].texCoords = sf::Vector2f(2, 40);
		break;
	case 1:
		quad[0].texCoords = sf::Vector2f(47, 2);
		quad[1].texCoords = sf::Vector2f(85, 2);
		quad[2].texCoords = sf::Vector2f(85, 40);
		quad[3].texCoords = sf::Vector2f(47, 40);
		break;
	case 3:
		quad[0].texCoords = sf::Vector2f(47, 100);
		quad[1].texCoords = sf::Vector2f(85, 100);
		quad[2].texCoords = sf::Vector2f(85, 128);
		quad[3].texCoords = sf::Vector2f(47, 128);
		break;
	default:
		break;
	}
	
}

void TileMap::loadTexture(const std::string& tileset)
{
	// on charge la texture du tileset
	if (!m_tileset.loadFromFile(tileset)) {
		std::printf("erreur");
	}
	m_tileset.setSmooth(true);
}

void TileMap::setUpQuad(sf::Vertex* quad, sf::Vector2u tileSize, const int tileType, 
	const int line, const int col, const int width)
{
	quad[0].position = sf::Vector2f((line)*tileSize.x, (col)*tileSize.y);
	quad[1].position = sf::Vector2f((line + 1)*tileSize.x, (col)*tileSize.y);
	quad[2].position = sf::Vector2f((line + 1)*tileSize.x, (col + 1)*tileSize.y);
	quad[3].position = sf::Vector2f((line)*tileSize.x, (col + 1)*tileSize.y);

	this->setTextureOnQuad(quad, tileType);
}

void TileMap::setUpTiles(sf::Vector2u tileSize, const int tilesType, const int line, const int col, TileWrapper** tiles)
{
	tiles[col][line].setPosition((line)*tileSize.x, (col)*tileSize.y);
	tiles[col][line].setSize(sf::Vector2f(tileSize.x,tileSize.y));
	tiles[col][line].setTileType(tilesType);
	tiles[col][line].setCoords(col, line);
}

void TileMap::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	
	states.transform *= getTransform(); 
	states.texture = &m_tileset;

	target.draw(m_vertices, states);

}

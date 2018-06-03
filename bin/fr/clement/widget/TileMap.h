
#include <SFML/graphics.hpp>
using namespace sf;

class TileMap:public sf::Drawable, public sf::Transformable
{
public:
	TileMap();
	~TileMap();
	void loadTiles(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	

private:
	
	void setTextureOnQuad(sf::Vertex * quad,int indice);
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	
};


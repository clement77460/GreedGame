#include"TilesInterface.h"
class WallTiles:public TilesInterface
{
public:
	WallTiles();
	~WallTiles();

	virtual bool isAvailable() const;
	virtual void toString();
};


#include"TilesInterface.h"

class GroundTiles:public TilesInterface
{
public:
	GroundTiles();
	~GroundTiles();
	virtual bool isAvailable() const;
};


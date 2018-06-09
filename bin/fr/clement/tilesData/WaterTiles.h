#include"TilesInterface.h"
class WaterTiles: public TilesInterface
{
public:
	WaterTiles();
	~WaterTiles();

	virtual bool isAvailable() const;
};
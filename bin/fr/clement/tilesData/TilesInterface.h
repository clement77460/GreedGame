#ifndef TILESINTERFACE_H
#define TILESINTERFACE_H


class TilesInterface
{
public:

	virtual bool isAvailable() const = 0; //virtuelle pure (classe abstraite car interface n'existe pas)
	virtual void toString() = 0;
	virtual void setSomeone(bool flag) {
		this->hasSomeone = flag;
	}

	virtual void setMovable(bool flag) {
		this->isMovable = flag;
	}

protected:
	bool hasSomeone = false;
	bool isMovable = true;
};


#endif

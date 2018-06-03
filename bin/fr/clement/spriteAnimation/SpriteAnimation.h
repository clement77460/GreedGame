
enum directions {
	down,
	left,
	right,
	up
};

class SpriteAnimation
{
public:
	SpriteAnimation();
	~SpriteAnimation();
	void increaseMouvement();
	void changeDirection(const int test);
	int getMouvement();
	int getDirection();

private:
	directions direction=down;
	int mouvement=1;
	
};


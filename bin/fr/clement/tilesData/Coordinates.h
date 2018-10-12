
class Coordinates
{
public:
	Coordinates(int line,int column);
	Coordinates();
	~Coordinates();

	void setLine(int line);
	void setColumn(int column);

	int getLine();
	int getColumn();

	

	

private:
	int line;
	int column;
};


bool operator== (Coordinates a, Coordinates b);
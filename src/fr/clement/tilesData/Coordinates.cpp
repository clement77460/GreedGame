#include "..//../../bin/fr/clement/tilesData/Coordinates.h"


Coordinates::Coordinates()
{
}


Coordinates::Coordinates(int line, int column)
{
	this->line = line;
	this->column = column;
}

Coordinates::~Coordinates()
{
}

void Coordinates::setLine(int line)
{
	this->line = line;
}

void Coordinates::setColumn(int column)
{
	this->column = column;
}

int Coordinates::getLine()
{
	return this->line;
}

int Coordinates::getColumn()
{
	return this->column;
}

bool operator== (Coordinates a, Coordinates b) {
	if (a.getLine() == b.getLine()) {
		if (a.getColumn() == b.getColumn()) {
			return true;
		}
	}
	return false;
}




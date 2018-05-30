#pragma once
#include <vector>
class Atom {
public:
	Atom();
	~Atom();
	void draw();
};

class Brick : Atom
{
	Atom atom;
	int nCol;
	int nRow;
	float r, g, b;
public:
	float x, y, z;  // position
public:
	Brick();
	Brick(int row, int col);
	~Brick();
	void setNumberOfRowAndColumn(int r, int c);
	void draw();
	void setColor(float red, float green, float blue);
	void move(float x, float y, float z);
	void setPosition(float newx, float newy, float newz);
};

class Bricks {
	std::vector<Brick> bricks;
public:
	Bricks();
	~Bricks();
	void draw();
	void add(Brick b);
	void erase();
	unsigned getSize();
};


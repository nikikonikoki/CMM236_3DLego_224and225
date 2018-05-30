#pragma once
#include "Brick.h"
#include <vector>

class Lego
{
	Bricks bricks;   // array of brick that already placed
public:
	Brick brick;   // current brick
public:
	Lego();
	~Lego();
	void draw();
};


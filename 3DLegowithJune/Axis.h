#pragma once
class Axis
{
	float x, y, z;

public:
	Axis();
	~Axis();
	Axis(float lengthx, float lengthy, float lengthz);
	static void scaleTwice();
	static void draw();
};


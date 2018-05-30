#include "Lego.h"



Lego::Lego()
{
	brick.setColor(1, 0.8, 0);
	brick.setNumberOfRowAndColumn(2, 2);
	
}


Lego::~Lego()
{
}

void Lego::draw() {
	bricks.draw();
	brick.draw();
}
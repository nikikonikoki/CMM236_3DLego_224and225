#include "Axis.h"
#include <GL/glut.h>


Axis::Axis()
{
}


Axis::~Axis()
{
}

void Axis::draw() {
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0);
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1);
	glEnd();
}

Axis::Axis(float lengthx, float lengthy, float lengthz) {

}
void Axis::scaleTwice() {
	glScalef(2, 2, 2);
}

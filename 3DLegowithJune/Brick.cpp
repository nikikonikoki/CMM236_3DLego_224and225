#include "Brick.h"
#include <GL/glut.h>
#include<cmath>

Atom::Atom() {

}

Atom::~Atom() {

}

void Atom::draw() {
	const float twoPi = 3.14159265*2.0;
	float radius = 0.1;

	// determine row and column properties
	// draw with opengl
	//draw 1 piece and translate with(i,j)
	glPushMatrix();
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glScalef(0.5, 0.5, 0.5);
		glutSolidCube(2.0);
		glPushMatrix();
			GLUquadricObj *quadratic;
			quadratic = gluNewQuadric();
			//glTranslatef(0, 0, -1.5);
			glPushMatrix();
				glRotatef(90, -1, 0, 0);
				//glColor3f(0.8, 0, 0); // (204,0,0) divided by 255 
				gluCylinder(quadratic, 0.5, 0.5, 1.2, 20, 20);
				gluDeleteQuadric(quadratic);
			glPopMatrix();
			glPushMatrix();	
				float X = 0, Y = 0, Z = 0;
				//glColor3f(1, 0, 0);
				//glScalef(5, 5, 5);
				glPushMatrix();
					glTranslatef(0, 1.2, 0);
					glBegin(GL_TRIANGLE_FAN);
						glVertex3f(0, 0, 0);
						for (int i = 0; i<40; i++)
						{
							float theta = i / 40 * twoPi;
							float x = sin(theta)*radius;
							float z = cos(theta)*radius;
							glVertex3f(x, 0, z);
						}
					glEnd();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

Brick::Brick()
{
	nCol = 2;
	nRow = 2;
	r = 0;
	g = 1; 
	b = 0;
	x = y = z = 0;
}

Brick::Brick(int row, int col) {
	nCol = col;
	nRow = row;
	r = 0;
	g = 1; 
	b = 0; 
	x = y = z = 0; 
}

Brick::~Brick()
{
}

void Brick::draw() {
	glPushMatrix();
	glTranslatef(x, y, z);
	glColor3f(r, g, b);
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++) {
			glPushMatrix();
				glTranslatef(j,0,i);
				atom.draw();
			glPopMatrix();
		}
	}
	glPopMatrix();
}

void Brick::setNumberOfRowAndColumn(int r, int c) {
	nRow = r;
	nCol = c;
}
void Brick::move(float x, float y, float z)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glPopMatrix();
}
void Brick::setPosition(float newx, float newy, float newz) {
	x = newx;
	y = newy;
	z = newz;
}

void Brick::setColor(float red, float green, float blue) {
	r = red;
	g = green;
	b = blue;
}

Bricks::Bricks() {
	bricks.resize(0);
}
Bricks::~Bricks() {

}
void Bricks::draw() {
	for (int i = 0; i < bricks.size(); i++) {
		bricks[i].draw();
	}
}
void Bricks::add(Brick b) {
	bricks.push_back(b);
}
void Bricks::erase() {
	bricks.pop_back();
}

unsigned Bricks::getSize() {
	return bricks.size();
}

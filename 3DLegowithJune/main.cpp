#include <stdlib.h>
//#include <windows.h>
#include <GL/glut.h>
//#include <color.h>
#include<cmath>
#include "Brick.h"
#include "Axis.h"
#include <vector>
#include "Lego.h"
using namespace std;
std::vector<Brick> br;



Lego lego;
float width = 500;
float height = 500;

float left = -4.0, right = 4.0, bottom = -4.0f, top = 4.0f;
float near = 4.0f, far = -40.0f;
float angle = 0.0;
float fov = 55.0;
float leftAspect = left, rightAspect=right, bottomAspect=bottom, topAspect=top;
float unitWindowWidth = 0, unitWindowHeight = 0;
static GLfloat theta[] = { 0.0,0.0,0.0 };
static GLint axis = 2;

float pi = 3.14;
int MouseS = true;

float X, Y, x, y;
double radius = 0.1;

float a,b,c=0;

/*void mouse_event(int x, int y) {

}*/

/*int mouseButton;
int oldX, newX, oldY, newY;
bool rotaetAxixX = false;
float rotateAngle = 0.0;
float depth;


void checkState(int state, int x, int y) {
	switch (state) {
	case GLUT_UP:
		//cout<<" UP"<<endl;
		break;
	case GLUT_DOWN:
		//cout<<" DOWN"<<endl;
		break;
	};
}

void mouseEvent(int button, int state, int x, int y)
{
	mouseButton = button;
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			oldX = x;
			oldY = y;
		}
		checkState(state, x, y);
		break;
	case GLUT_RIGHT_BUTTON:
		//cout<<"RIGHT";
		checkState(state, x, y);
		break;
	case GLUT_MIDDLE_BUTTON:
		//cout<<"MIDDLE";
		checkState(state, x, y);
		break;
	};
}*/
int m = 0;
void display(void) {
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);

	/* display callback, clear frame buffer and z buffer,
	rotate cube and draw, swap buffers */
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1,1,1,0,0,0,0,1,0);
	
	lego.draw();
	if (m == 1)
	{
		glTranslated(3+a, 0+b, 0+c);
		lego.draw();
	}

	//Axis::scaleTwice();
	Axis::draw();

	glFlush();
	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON & & state == GLUT_DOWN)
	{
		MouseS = true;
	}
	else
	{
		MouseS = false;
	}
	glutPostRedisplay();
}



void motion(int x, int y) {

}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1': //add new lego
		m = m + 1;
		break;
	case 'd':
		a = a + 1;
		break;
	case 'D':
		a = a - 1;
		break;
	case 's':
		b = b + 1;
		break;
	case'S':
		b = b - 1;
	case 'a':
		c = c + 1;
		break;
	case 'A':
		c = c - 1;
		break;
	}
	glutPostRedisplay();
}
void myReshape(int w, int h) {
	width = w;
	height = h;
	float aspect = (float)w / h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (aspect >= 1.0) {
		leftAspect = left*aspect;
		rightAspect = right*aspect;
		bottomAspect = bottom;
		topAspect = top;
	}
	else {
		leftAspect = left;
		rightAspect = right;
		topAspect = top / aspect;
		bottomAspect = bottom / aspect;
	}
	glOrtho(leftAspect, rightAspect, bottomAspect, topAspect, near,far);
	glutPostRedisplay();
}
void init() {
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	/*glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, colors);*/
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
}
void passiveMotion(int x, int y) {
	if (MouseS == true) {
		unitWindowWidth = rightAspect - leftAspect;
		unitWindowHeight = topAspect - bottomAspect;
		float unitX = ((float)x / width)*unitWindowWidth - unitWindowWidth / 2.0;
		float unitY = ((float)(height - y) / height)*unitWindowHeight - unitWindowHeight / 2.0;
		lego.brick.setPosition(unitX, unitY, lego.brick.z);
		glutPostRedisplay();
	}
}

int main(int argc, char **argv) {

	/* need both double buffering and z buffer */

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("3DLego of Niki224&June225");

	init();

	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutIdleFunc(NULL);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMotionFunc(motion);
	glutPassiveMotionFunc(passiveMotion);
	glutMainLoop();

	return 0;
}


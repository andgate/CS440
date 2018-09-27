// Windows imports
#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include "glut.h"

// Linux imports
//#include <GL/glut.h>


void Display();

void Init(void);

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("my first attempt");
	glutDisplayFunc(Display);
	Init();
	glutMainLoop();

	return 0;
}

void hardwiredHouse(void)
{
	// draw the shell of house
	glBegin(GL_LINE_LOOP);
		glVertex2i(40, 40);
		glVertex2i(40, 90);
		glVertex2i(70, 120);
		glVertex2i(100, 90);
		glVertex2i(100, 40);
	glEnd();

	// draw the chimney
	glBegin(GL_LINE_STRIP);
		glVertex2i(50, 100);
		glVertex2i(50, 120);
		glVertex2i(60, 120);
		glVertex2i(60, 110);
	glEnd();

	// draw the door
	glBegin(GL_LINE_STRIP);
		glVertex2i(50, 40);
		glVertex2i(50, 80);
		glVertex2i(60, 80);
		glVertex2i(60, 40);
	glEnd();

	// draw the window
	glBegin(GL_LINE_LOOP);
		glVertex2i(70, 75);
		glVertex2i(70, 90);
		glVertex2i(80, 90);
		glVertex2i(80, 75);
	glEnd();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	hardwiredHouse();
	glFlush();
}

void Init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(1.0,200.0,0.0,200.0);
}


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
	glutCreateWindow("Parameterized House");
	glutDisplayFunc(Display);
	Init();
	glutMainLoop();

	return 0;
}


struct GLintPoint { int x, y; };


void parameterizedHouse(GLintPoint peak, GLint width, GLint height)
{
	GLintPoint chimneyPoint = { peak.x - width/4, peak.y - height/4 };
	GLint chimneyWidth = width/10;
	GLint chimneyHeight = width/10;
	GLint chWidth = width/10;

	// Points for the shell of the house
	GLintPoint p1 = { peak.x,             peak.y }; 
	GLintPoint p2 = { peak.x + width / 2, peak.y - 3 * height /8 }; 
	GLintPoint p3 = { peak.x + width / 2, peak.y -     height    }; 
	GLintPoint p4 = { peak.x - width / 2, peak.y -     height    };  
	GLintPoint p5 = { peak.x - width / 2, peak.y - 3 * height /8 }; 

	// draw the shell of house
	glBegin(GL_LINE_LOOP);
		glVertex2i(p1.x, p1.y);
		glVertex2i(p2.x, p2.y);
		glVertex2i(p3.x, p3.y);
		glVertex2i(p4.x, p4.y);
		glVertex2i(p5.x, p5.y);
	glEnd();

	// draw the shell of house
	/*glBegin(GL_LINE_LOOP);
		glVertex2i(40, 40);
		glVertex2i(40, 90);
		glVertex2i(70, 120);
		glVertex2i(100, 90);
		glVertex2i(100, 40);
	glEnd();*/

	// Chimney Points
	GLintPoint ch1 = { p5.x + (p1.x - p5.x)/4  , p5.y + (p1.y - p5.y)/4 };
	GLintPoint ch2 = { ch1.x                   , peak.y };
	GLintPoint ch3 = { p5.x + (p1.x - p5.x)*3/4, peak.y };
	GLintPoint ch4 = { ch3.x                   , p5.y + (p1.y - p5.y)*3/4 };

	// draw the chimney
	glBegin(GL_LINE_STRIP);
		glVertex2i(ch1.x, ch1.y);
		glVertex2i(ch2.x, ch2.y);
		glVertex2i(ch3.x, ch3.y);
		glVertex2i(ch4.x, ch4.y);
	glEnd();

	//// draw the door
	//glBegin(GL_LINE_STRIP);
	//	glVertex2i(50, 40);
	//	glVertex2i(50, 80);
	//	glVertex2i(60, 80);
	//	glVertex2i(60, 40);
	//glEnd();

	//// draw the window
	//glBegin(GL_LINE_LOOP);
	//	glVertex2i(70, 75);
	//	glVertex2i(70, 90);
	//	glVertex2i(80, 90);
	//	glVertex2i(80, 75);
	//glEnd();
}

void Display()
{
	GLintPoint p = {100, 100};

	glClear(GL_COLOR_BUFFER_BIT);
	parameterizedHouse(p, 50, 50);
	parameterizedHouse(p, 50, 50);
	parameterizedHouse(p, 50, 50);
	parameterizedHouse(p, 50, 50);
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


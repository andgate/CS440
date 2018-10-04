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
    int chimneyWidth = (p1.x - p5.x)/3;
	GLintPoint ch1 = { p5.x + chimneyWidth , p5.y + (p1.y - p5.y)/3 };
	GLintPoint ch2 = { ch1.x               , peak.y - height/32};
	GLintPoint ch3 = { ch1.x + chimneyWidth, peak.y - height/32};
	GLintPoint ch4 = { ch3.x               , p5.y + (p1.y - p5.y)*2/3 };

	// draw the chimney
	glBegin(GL_LINE_STRIP);
		glVertex2i(ch1.x, ch1.y);
		glVertex2i(ch2.x, ch2.y);
		glVertex2i(ch3.x, ch3.y);
		glVertex2i(ch4.x, ch4.y);
	glEnd();

    // Door dimensions and points
    int doorWidth  = width/5;
    int doorHeight = height/2;
    GLintPoint d1 = { p4.x + width/8  , p4.y };
	GLintPoint d2 = { d1.x            , d1.y + doorHeight };
	GLintPoint d3 = { d1.x + doorWidth, d2.y };
	GLintPoint d4 = { d3.x            , d1.y };

	// draw the door
	glBegin(GL_LINE_STRIP);
		glVertex2i(d1.x, d1.y);
		glVertex2i(d2.x, d2.y);
		glVertex2i(d3.x, d3.y);
		glVertex2i(d4.x, d4.y);
	glEnd();


    // Window size and points
    int windowWidth  = width/5;
	int windowHeight  = height/5;
    GLintPoint w1 = { p4.x + width*5/8 , p4.y + height*7/16 };
	GLintPoint w2 = { w1.x             , w1.y + windowHeight };
	GLintPoint w3 = { w1.x + windowWidth, w2.y };
	GLintPoint w4 = { w3.x             , w1.y };

	// draw the window
	glBegin(GL_LINE_LOOP);
		glVertex2i(w1.x, w1.y);
		glVertex2i(w2.x, w2.y);
		glVertex2i(w3.x, w3.y);
		glVertex2i(w4.x, w4.y);
	glEnd();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	int width = 100;
    int height = 100;
	GLintPoint p1 = {width/1.5, 475};
	parameterizedHouse(p1, width, height);

	GLintPoint p2 = {p1.x+width, p1.y};
	int width2 = width / 2;
	parameterizedHouse(p2, width2, height);

	GLintPoint p3 = {p2.x+width, p2.y};
	int width3 = width;
	int height3 = height / 2;
	parameterizedHouse(p3, width3, height3);

	glFlush();
}

void Init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(1.0,640.0,0.0,480.0);
}


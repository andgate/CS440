// Windows imports
#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include "glut.h"

// Linux imports
//#include <GL/glut.h>


class GLintPoint {
public:
	int x, y;
	GLintPoint() : x(0), y(0) {}
	GLintPoint(int newX, int newY)
		: x(newX), y(newY)
	{}
};

class GLintPointArray {
   public:
      int num;      
	  GLintPoint pt[100];
};

void drawPolyLine(GLintPointArray poly, int closed)
{
	glBegin(closed ? GL_LINE_LOOP : GL_LINE_STRIP);

		for(int i = 0; i < poly.num; i++)
			glVertex2i(poly.pt[i].x, poly.pt[i].y);
	
	glEnd();
	glFlush();
}

void Display();

void Init(void);

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Draw Poly Line");
	glutDisplayFunc(Display);
	Init();
	glutMainLoop();

	return 0;
}

void Display()
{

	GLintPointArray points;
	points.num = 6;
	points.pt[0] = GLintPoint(10, 10);
	points.pt[1] = GLintPoint(10, 100);
	points.pt[2] = GLintPoint(100, 100);
	points.pt[3] = GLintPoint(150, 100);
	points.pt[4] = GLintPoint(150, 150);
	points.pt[5] = GLintPoint(200, 150);

	glClear(GL_COLOR_BUFFER_BIT);
    drawPolyLine(points, false);
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


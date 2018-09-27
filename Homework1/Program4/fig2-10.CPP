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
	glutCreateWindow("A polyline and a polygon");
   glutDisplayFunc(Display);
   Init();
	glutMainLoop();

  return 0;
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
      glVertex2i(20,10);
      glVertex2i(50,10);
      glVertex2i(20,80);
      glVertex2i(50,80);
   glEnd();

   glBegin(GL_LINE_LOOP);
      glVertex2i(70,10);
      glVertex2i(100,10);
      glVertex2i(70,80);
      glVertex2i(100,80);
   glEnd();
   glFlush();
}

void Init()
{
	glClearColor(1.0,1.0,1.0,0.0);
   glColor3f(0.0f,0.0f,0.0f);
   glPointSize(4.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(1.0,150.0,0.0,100.0);
}


// Windows imports
/*
#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <iostream.h>
#include "glut.h"
*/

// Linux imports
#include <GL/glut.h>


void Display();

void Init(void);

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Thin Lines");
   glutDisplayFunc(Display);
   Init();
	glutMainLoop();

  return 0;
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
    glVertex2i(10, 20); // first horizontal line
    glVertex2i(40, 20);
    glVertex2i(20, 10); // first vertical line
    glVertex2i(20, 40);
    glVertex2i(10, 30); // Second horizontal line
    glVertex2i(40, 30);
    glVertex2i(30, 10); // Second vertical line
    glVertex2i(30, 40);
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
   gluOrtho2D(1.0,640.0,0.0,480.0);
}

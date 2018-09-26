// Windows imports
/*
#include <windows.h>
#include <math.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include "glut.h"
*/

// Linux imports
#include <GL/glut.h>
#include <math.h>

void Display();
void Init(void);

const int screenWidth = 640;
// width of screen window in pixels
const int screenHeight = 480;
// height of screen window in pixels
GLdouble A, B, C, D;  // values used for scaling and shifting


int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenWidth);
	glutInitWindowPosition(100,150);

	glutCreateWindow("Dot Plot of a Function");
   glutDisplayFunc(Display);
   Init();
	glutMainLoop();

  return 0;
}

void Display()
{
  glClear(GL_COLOR_BUFFER_BIT);  // clear the screen
  glBegin(GL_POINTS);
  for(GLdouble x = 0; x < 4.0 ; x += 0.005)
  {
    GLdouble func = exp(-x) * cos(2 * 3.14159265 * x);
    glVertex2d(A * x + B, C * func + D);
  }
  glEnd();
  glFlush();  // send all output to display
}

void Init()
{
	glClearColor(1.0,1.0,1.0,0.0);
  glColor3f(0.0f,0.0f,0.0f);
  glPointSize(4.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);

  A = screenWidth / 4.0; // set values used for scaling and shifting
  B = 0.0;
  C = D = screenHeight / 2.0;
}

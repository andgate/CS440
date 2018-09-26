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

void Sierpinski();
void Display();

void Init(void);

int random(int m) { return rand() % m; }

class GLintPoint {
public:
  GLint x, y;
};


void drawDot(int x, int y) {
  glBegin(GL_POINTS);
    glVertex2i(x, y);
  glEnd();
}


int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Sierpinski");
  glutDisplayFunc(Display);
  Init();
	glutMainLoop();

  return 0;
}

void Display()
{
  Sierpinski();
}

void Init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
  glColor3f(0.0f,0.0f,0.0f);
  glPointSize(4.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(1.0,640.0,0.0,480.0);
}


void Sierpinski()
{
  GLintPoint T[3]= {{10,10},{300,30},{200, 300}};
  int index = random(3);         // 0, 1, or 2 equally likely
  GLintPoint point = T[index];   // initial point
  drawDot(point.x, point.y);     // draw initial point

  for(int i = 0; i < 1000; i++)  // draw 1000 dots
  {
      index = random(3);
      point.x = (point.x + T[index].x) / 2;
      point.y = (point.y + T[index].y) / 2;
      drawDot(point.x,point.y);
  }

  glFlush();
}


#include <math.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;
float x1, x2, yr1, yr2, x, y, steps, dx, dy, xinc, yinc;
void init(void)
{
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
    glMatrixMode(GL_MODELVIEW);
}
void display()
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPointSize(2.0);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    dx = x2 - x1;
    dy = yr2 - yr1;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    x = x1;
    y = yr1;
    xinc = dx / steps;
    yinc = dy / steps;
    glVertex2f(round(x), round(y));
    for (i = 0; i < steps; i++)
    {
        x = x + xinc;
        y = y + yinc;
        glVertex2f(round(x), round(y));
    }
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    cin >> x1 >> x2 >> yr1 >> yr2;
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("DDA Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
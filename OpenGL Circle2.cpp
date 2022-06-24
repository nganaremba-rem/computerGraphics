#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#define pi 3.142857
void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.8);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-780, 780, -420, 420);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    float x, y, i;
    for (i = 0; i < (2 * pi); i += 0.001)
    {
        x = 180 * cos(i);
        y = 180 * sin(i);
        glVertex2i(x, y);
    }
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("CIRCLE");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}
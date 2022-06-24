#include <GL/glut.h>
#include <stdio.h>

int x1, Y1, x2, y2;

void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0, 1, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void bresenham()
{
    int x = x1, y = Y1, dx, dy;
    dx = x2 - x1;
    dy = y2 - Y1;
    int decisionParameter = 2 * dy - dx;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    while (x <= x2)
    {
        glVertex2i(x, y);
        x++;
        if (decisionParameter < 0)
        {
            decisionParameter = decisionParameter + 2 * dy;
        }
        else
        {
            decisionParameter = decisionParameter + 2 * dy - 2 * dx;
            y++;
        }
    }
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    x1 = 10;
    x2 = 400;
    Y1 = 20;
    y2 = 100;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham");
    myInit();
    glutDisplayFunc(bresenham);
    glutMainLoop();
}
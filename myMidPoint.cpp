#include <stdio.h>
#include <GL/glut.h>

int X1, Y1, X2, Y2;

void init()
{
    glClearColor(1, 1, 1, 0);
    glColor3f(1, 0, 0);
    gluOrtho2D(-10, 500, -10, 500);
}

void midPoint()
{
    int x = X1, y = Y1, dInitital, deltaD, dx, dy;
    dx = X2 - X1;
    dy = Y2 - Y1;

    dInitital = 2 * dy - dx;
    deltaD = 2 * (dy - dx);

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    while (x <= X2)
    {
        glVertex2i(x, y);
        x++;
        if (dInitital < 0)
        {
            dInitital += 2 * dy;
        }
        else
        {
            dInitital += 2 * deltaD;
            y++;
        }
    }
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    X1 = 1;
    X2 = 500;
    Y1 = 6;
    Y2 = 300;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(10, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Mid Point Line Algo");
    init();

    glutDisplayFunc(midPoint);
    glutMainLoop();
}

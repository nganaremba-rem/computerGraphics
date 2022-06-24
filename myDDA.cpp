#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

double X1, Y1, X2, Y2;

double roundValue(double value)
{
    return floor(value + 0.5);
}

void myInit(void)
{
    glClearColor(1.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    // glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 500, -100, 500);
}

void DDA()
{
    double step, dx, dy, xinc, yinc;
    dx = X2 - X1;
    dy = Y2 - Y1;

    step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    xinc = dx / step;
    yinc = dy / step;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for (int i = 0; i <= step; i++)
    {
        printf("x: %f y: %f\n", roundValue(X1), roundValue(Y1));
        glVertex2d(roundValue(X1), roundValue(Y1));
        X1 += xinc;
        Y1 += yinc;
    }
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    X1 = -3;
    Y1 = 4;
    X2 = -10;
    Y2 = 7;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line");
    myInit();
    glutDisplayFunc(DDA);
    glutMainLoop();
}

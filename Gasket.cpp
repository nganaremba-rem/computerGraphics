#include <GL/glut.h>

void display(void)
{
    GLfloat vertices[3][2] = {{25.0, 25.0}, {50.0, 75.0}, {75.0, 25.0}};

    int i, j, k;
    // int rand();
    GLfloat p[2] = {33.0, 40.0};

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for (k = 0; k < 20000; k++)
    {
        j = rand() % 3;
        p[0] = (p[0] + vertices[j][0]) / 2.0;
        p[1] = (p[1] + vertices[j][1]) / 2.0;
        glVertex2fv(p);
    }
    glEnd();
    glFlush();
}
void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0, 250.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Sierpinsky Gasket");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
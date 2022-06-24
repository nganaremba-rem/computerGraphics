#include <GL/glut.h>
void display(void)
{
    GLfloat vertices[4][3] = {{-50.0, -50.0, -50.0}, {0.0, 50.0, 10.0}, {60.0, -10.0, 0.0}, {50.0, -50.0, 0.0}};

    int i, j, k;
    int rand();
    GLfloat p[3] = {25.0, 10.0, 25.0};

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for (k = 0; k < 20000; k++)
    {
        j = rand() % 4;
        p[0] = (p[0] + vertices[j][0]) / 2.0;
        p[1] = (p[1] + vertices[j][1]) / 2.0;
        p[2] = (p[2] + vertices[j][2]) / 2.0;
        glColor3f(p[0] / 250.0, p[1] / 250.0, p[2] / 250.0);
        glVertex3fv(p);
    }
    glEnd();
    glFlush();
}
void myinit()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Sierpinsky Gasket 3D");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}

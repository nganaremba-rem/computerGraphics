#include <GL/glut.h>
#include <math.h>
#define PI 3.14
using namespace std;
void init(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-120.0, 120.0, -120.0, 120.0, -120.0, 120.0);
    glMatrixMode(GL_MODELVIEW);
}
void CIRCLE()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 0, 0);
    GLint r = 30;
    GLdouble i = 0.0;
    for (i = 0; i <= 2 * PI; i += PI / 180)
        glVertex2d(r * cos(i), r * sin(i));
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("CIRCLE");
    init();
    glutDisplayFunc(CIRCLE);
    glutMainLoop();
    return 0;
}
#include <GL/glut.h>
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
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 60.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0, 60.0);
    glVertex2f(60.0, 60.0);
    glVertex2f(60.0, 0.0);
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("SQUARE");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
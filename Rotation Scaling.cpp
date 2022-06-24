#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glut.h>
void display();
void specialKeys();
double rotate_y = 0.0;
double rotate_x = 0.0;
double scale = 2.5;
double translate = 0.0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(translate, 0.0, 0.0);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glScaled(scale, scale, 0.0);
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1, 1, 0.0);
    glEnd();
    glFlush();
    glutSwapBuffers();
}
void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5.0;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5.0;
    else if (key == GLUT_KEY_UP)
        rotate_x += 5.0;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5.0;
    else if (key == GLUT_KEY_F1)
    {
        scale += 0.1;
    }
    else if (key == GLUT_KEY_F2)
    {
        scale -= 0.1;
    }
    else if (key == GLUT_KEY_F3)
    {
        translate += 0.1;
    }
    else if (key == GLUT_KEY_F4)
    {
        translate -= 0.1;
    }
    glutPostRedisplay();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Line and Transformations");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
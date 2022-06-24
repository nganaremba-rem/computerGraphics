#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
bool fullscreen = false;
float posx, posy, movespeedx, movespeedy;
bool init()
{
    glClearColor(0.93f, 0.93f, 0.93f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    return true;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    float PI = 3.14159265;
    float radius = 0.09f;
    if (posx + radius > 1.0f || posx - radius < -1.0f)
    {
        movespeedx *= -1;
    }
    if (posy + radius > 1.0f || posy - radius < -1.0f)
    {
        movespeedy *= -1;
    }
    posx += movespeedx;
    posy += movespeedy;
    glBegin(GL_POLYGON);
    for (float angle = 0; angle < 360; angle += 5)
    {
        float xc = sin(angle * PI / 180) * radius;
        float yc = cos(angle * PI / 180) * radius;
        glVertex3f(xc + posx, yc + posy, 0.0f);
    }
    glEnd();
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
    if (key == 27)
        exit(1);
}
void specialkeyboard(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_F1:
        fullscreen = !fullscreen;
        if (fullscreen)
            glutFullScreen();

        else
        {
            glutReshapeWindow(500, 500);
            glutPositionWindow(50, 50);
        }
        break;
    }
}
int main(int argc, char *argv[])
{
    srand(time(NULL));
    int step = 100;
    posx = (rand() % step) / step - 0.5f;
    posy = (rand() % step) / step - 0.5f;
    movespeedx = 0.0001f;
    movespeedy = 0.0002f;
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(720, 720);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("05-Primitives");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialkeyboard);
    if (!init())
        return 1;
    glutMainLoop();
    return 0;
}
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
using namespace std;

float ballX = -0.8f;
float ballY = -0.3f;
float ballZ = -1.2f;
float colR = 3.0;
float colG = 1.5;
float colB = 1.0;
float bgColR = 0.0;
float bgColG = 0.0;
float bgColB = 0.0;

static int flag = 1;

void drawBall(void)
{
    glColor3f(colR, colG, colB);
    glTranslatef(ballX, ballY, ballZ);
    glutSolidSphere(0.3, 30, 30);
}
void drawHut(void)
{
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(0.7, 0.0, -1.0);
    glVertex3f(0.5, -0.5, -1.0);
    glVertex3f(0.9, -0.5, -1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(0.5, -0.5, -1.0);
    glVertex3f(0.9, -0.5, -1.0);
    glVertex3f(0.9, -0.8, -1.0);
    glVertex3f(0.5, -0.8, -1.0);
    glEnd();
}
void drawHill(void)
{
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2.0, 1.0, 1.0);
    glVertex3f(0.9, 1.0, 1.0);
    glVertex3f(0.9, 2.0, 1.0);
    glVertex3f(2.0, 2.0, 1.0);
    glEnd();
}
void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
}
void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(bgColR, bgColG, bgColB, 0.0);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    glPushMatrix();
    drawBall();
    glPopMatrix();
    glPushMatrix();
    drawHut();
    glPopMatrix();

    glPushMatrix();
    drawHill();
    glPopMatrix();

    glutSwapBuffers();
}

void update(int value)
{
    if (ballX > 0.9f)
    {
        ballX = -0.8f;
        ballY = -0.3f;
        flag = 1;
        colR = 2.0;
        colG = 1.5;
        colB = 1.0;
        bgColB = 0.0;
    }
    if (flag)
    {
        ballX += 0.001f;
        ballY += 0.0007f;
        colR -= 0.001;
        colG += 0.005;
        bgColB += 0.001;

        if (ballX > 0.01)
        {
            flag = 0;
        }
    }
    if (!flag)
    {
        ballX += 0.001f;
        ballY -= 0.0007f;
        colR += 0.001;
        colB -= 0.01;
        bgColB -= 0.001;

        if (ballX < -0.3)
        {
            flag = 1;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutCreateWindow("The sun and the house");
    initRendering();
    glutDisplayFunc(drawScene);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return (0);
}
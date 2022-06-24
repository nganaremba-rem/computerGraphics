#include <windows.h>
#include <GL/glut.h>
#define SunSize 0.9
#define EarthSize 0.3
#define MoonSize 0.1

GLfloat SpeedMultiplicator = 1.0;
GLfloat DaysPerYear = 10.0;
GLfloat year = 0.0;
GLfloat day = 0.0;
GLfloat moonAroundEarth = 0.0;
GLfloat moonItself = 0.0;
GLfloat EarthOrbitRadius = 1.25;
GLfloat MoonOrbitRadius = 0.20;
GLfloat daySpeed = 5.0 * SpeedMultiplicator;
GLfloat yearSpeed = DaysPerYear / 360.0 * daySpeed * SpeedMultiplicator;
GLfloat moonAroundEarthSpeed = 1.25 * SpeedMultiplicator;
GLfloat moonItselfSpeed = 1 * SpeedMultiplicator;

void RenderScene(void)
{
    glPushMatrix();

    gluLookAt(0.0, 0.0, -4.0, 0.0, 0.0, 1.0, 0.0, -3.0, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    glutSolidSphere(SunSize, 50, 50);
    glRotatef(year, 0.0, 1.0, 0.0);
    glTranslatef(EarthOrbitRadius, 0.0, 0.0);
    glPushMatrix();
    glRotatef(day, 0.25, 1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glutSolidSphere(EarthSize, 10, 10);
    glPopMatrix();
    glRotatef(moonAroundEarth, 0.0, 1.0, 0.0);
    glTranslatef(MoonOrbitRadius, 0.0, 0.0);
    glRotatef(moonItself, 0.0, 1.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(MoonSize, 8, 8);
    glPopMatrix();
    glPopMatrix();
}

void Init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearDepth(10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    RenderScene();
    glFlush();
    glutSwapBuffers();
}

void Reshape(int x, int y)
{

    if (y == 0)
        return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y);
    Display();
}

void Idle(void)
{

    day += daySpeed;
    year += yearSpeed;
    moonItself += moonItselfSpeed;
    moonAroundEarth += moonAroundEarthSpeed;

    Display();
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Practical4");
    Init();
    glutReshapeFunc(Reshape);
    glutDisplayFunc(Display);
    glutIdleFunc(Idle);
    glutMainLoop();
    return 0;
}
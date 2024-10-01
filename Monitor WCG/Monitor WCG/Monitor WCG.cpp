#include <iostream>
#include <cmath>

#include <GL/glew.h>
#include <GL/freeglut.h> 

float rotationAngle = 0.0f;

// Drawing routine.
void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Set the camera position
    gluLookAt(0.0, 2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Apply rotation
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);

    // Draw base (kaki persegi)
    glColor3f(0.2, 0.2, 0.2);  // Dark gray
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glScalef(0.8, 0.1, 0.6);
    glutSolidCube(1.0);
    glPopMatrix();

    // Draw neck (leher persegi)
    glColor3f(0.3, 0.3, 0.3);  // Slightly lighter gray
    glPushMatrix();
    glTranslatef(0.0, 0.2, 0.0);
    glScalef(0.1, 0.5, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Draw monitor head
    glColor3f(0.1, 0.1, 0.1);  // Very dark gray for monitor frame
    glPushMatrix();
    glTranslatef(0.0, 0.8, 0.0);
    glScalef(1.6, 1.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Draw screen
    glColor3f(0.7, 0.7, 0.7);  // Light gray for screen
    glPushMatrix();
    glTranslatef(0.0, 0.8, 0.052);
    glScalef(1.5, 0.9, 0.001);
    glutSolidCube(1.0);
    glPopMatrix();

    glutSwapBuffers();
}

// Initialization routine.
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case 'a':
        rotationAngle += 5.0f;
        if (rotationAngle > 360.0f) rotationAngle -= 360.0f;
        glutPostRedisplay();
        break;
    case 'd':
        rotationAngle -= 5.0f;
        if (rotationAngle < 0.0f) rotationAngle += 360.0f;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

// Main routine.
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Monitor");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);

    glewExperimental = GL_TRUE;
    glewInit();

    setup();

    glutMainLoop();

    return 0;
}
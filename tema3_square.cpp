#include <GL/freeglut.h>
#include "globals.h"

float oy = 0.0;

static void update_tema3_square(int value) {
    oy += 0.01;
    if (oy > 1.0) oy = -1.0;
    angle += 1.0;
    glutPostRedisplay();
    glutTimerFunc(16, update_tema3_square, 0);
}

void drawSquare() {
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.1, -0.1);
    glVertex2f(0.1, -0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(-0.1, 0.1);
    glEnd();
}

void display_tema3_square() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(0.0, oy, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    drawSquare();
    glPopMatrix();
    glFlush();
}

void run_tema3_square() {
    int argc = 1;
    char* argv[1] = {(char*)"Tema3_Square"};
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tema 3 Square");
    glutDisplayFunc(display_tema3_square);
    glutTimerFunc(16, update_tema3_square, 0);
    glutMainLoop();
}

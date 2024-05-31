#include <GL/freeglut.h>
#include "globals.h"
#include <cmath>

float angle = 0.0;

const int numDominoes = 10;
const float dominoWidth = 0.1;
const float dominoHeight = 0.5;
const float dominoGap = 0.15;

float angles[numDominoes];
bool falling[numDominoes];

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    for (int i = 0; i < numDominoes; ++i) {
        angles[i] = 0.0;
        falling[i] = false;
    }
    falling[0] = true;
}

void drawDomino(float x, float angle) {
    glPushMatrix();
    glTranslatef(x, 0.0, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-dominoWidth / 2, 0.0);
    glVertex2f(dominoWidth / 2, 0.0);
    glVertex2f(dominoWidth / 2, dominoHeight);
    glVertex2f(-dominoWidth / 2, dominoHeight);
    glEnd();
    glPopMatrix();
}

void display_proiect1() {
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; i < numDominoes; ++i) {
        float x = -1.0 + i * (dominoWidth + dominoGap);
        drawDomino(x, angles[i]);
    }
    glutSwapBuffers();
}

static void update_proiect1(int value) {
    for (int i = 0; i < numDominoes; ++i) {
        if (falling[i]) {
            angles[i] -= 1.0;
            if (angles[i] <= -20) {
                falling[i + 1] = true;
            }
            if (angles[i] <= -90.0) {
                angles[i] = -90.0;
                falling[i] = false;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(12, update_proiect1, 0);
}

void run_proiect1() {
    int argc = 1;
    char* argv[1] = {(char*)"Proiect1"};
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Proiect 1: 2D Domino Effect");
    init();
    glutDisplayFunc(display_proiect1);
    glutTimerFunc(16, update_proiect1, 0);
    glutMainLoop();
}

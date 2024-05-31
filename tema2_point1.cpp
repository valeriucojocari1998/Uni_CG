#include <GL/freeglut.h>

void drawPolygons() {
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-1.0, -1.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(1.0, -1.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(1.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 1.0);
    glVertex2f(-0.5, 0.0);
    glVertex2f(0.0, -0.5);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.0, 0.5);
    glEnd();
}

void display_tema2_point1() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawPolygons();
    glFlush();
}

void run_tema2_point1() {
    int argc = 1;
    char* argv[1] = {(char*)"Tema2_Point1"};
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tema 2 Point 1");
    glutDisplayFunc(display_tema2_point1);
    glutMainLoop();
}

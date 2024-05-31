#include <GL/freeglut.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void drawComplexModel() {
    glNewList(1, GL_COMPILE);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; ++i) {
        glVertex2f(cos(i * M_PI / 3), sin(i * M_PI / 3));
    }
    glEnd();
    glEndList();
}

void display_tema2_point3() {
    glClear(GL_COLOR_BUFFER_BIT);
    glCallList(1);
    glFlush();
}

void run_tema2_point3() {
    int argc = 1;
    char* argv[1] = {(char*)"Tema2_Point3"};
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tema 2 Point 3");
    drawComplexModel();
    glutDisplayFunc(display_tema2_point3);
    glutMainLoop();
}

#include <GL/freeglut.h>

void display_tema1_point1() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.5, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.5, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.0, 0.5);
    glEnd();
    glFlush();
}

void run_tema1_point1() {
    int argc = 1;
    char* argv[1] = {(char*)"Tema1_Point2"};
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tema 1 Point 2");
    glutDisplayFunc(display_tema1_point1);
    glutMainLoop();
}

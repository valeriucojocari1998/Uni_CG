#include <GL/freeglut.h>

void drawTriangles() {
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glEnd();

    glPolygonMode(GL_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.0, -0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
    glEnd();
}

void display_tema2_point2() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawTriangles();
    glFlush();
}

void run_tema2_point2() {
    int argc = 1;
    char* argv[1] = {(char*)"Tema2_Point2"};
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tema 2 Point 2");
    glutDisplayFunc(display_tema2_point2);
    glutMainLoop();
}

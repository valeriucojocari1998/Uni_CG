#include <GL/freeglut.h>

void display_tema1_point2() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.5, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.5, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.0, 0.5);
    glEnd();

    // Add text rendering here
    glColor3f(0.0, 0.0, 0.0); // Black color for text
    glRasterPos2f(-0.2f, 0.6f); // Position the text

    const char *text = "Hello OpenGL";
    for (const char *c = text; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    glFlush();
}

void run_tema1_point2() {
    int argc = 1;
    char* argv[1] = {(char*)"Tema1_Point3"};
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tema 1 Point 3");
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set white background
    glutDisplayFunc(display_tema1_point2);
    glutMainLoop();
}

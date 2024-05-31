#include <GL/freeglut.h>
#include <cmath>

float angle_planet = 0.0;
float angle_moon = 0.0;

void drawCircle(float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(100);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void display_tema3_solar() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw sun
    glColor3f(1.0, 1.0, 0.0); // Yellow
    drawCircle(0.1);

    // Draw planet
    glPushMatrix();
    glRotatef(angle_planet, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glColor3f(0.0, 0.0, 1.0); // Blue
    drawCircle(0.05);

    // Draw moon
    glRotatef(angle_moon, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glColor3f(0.5, 0.5, 0.5); // Gray
    drawCircle(0.02);
    glPopMatrix();

    glutSwapBuffers();
}

void update_tema3_solar(int value) {
    angle_planet += 0.5;
    angle_moon += 2.0;
    if (angle_planet > 360) angle_planet -= 360;
    if (angle_moon > 360) angle_moon -= 360;
    glutPostRedisplay();
    glutTimerFunc(16, update_tema3_solar, 0);
}

void run_tema3_solar() {
    int argc = 1;
    char* argv[1] = {(char*)"Tema3_Solar"};
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tema 3 Solar System");
    glutDisplayFunc(display_tema3_solar);
    glutTimerFunc(16, update_tema3_solar, 0);
    glutMainLoop();
}

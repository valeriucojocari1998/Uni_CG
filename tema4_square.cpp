#include <GL/freeglut.h>
#include "globals.h"

// Create a simple checkerboard texture
const int checkImageWidth = 64;
const int checkImageHeight = 64;
GLubyte checkImage[checkImageHeight][checkImageWidth][4];

GLuint texture;

void makeCheckImage() {
    int i, j, c;
    for (i = 0; i < checkImageHeight; i++) {
        for (j = 0; j < checkImageWidth; j++) {
            c = (((i & 0x8) == 0) ^ ((j & 0x8) == 0)) * 255;
            checkImage[i][j][0] = (GLubyte) c;
            checkImage[i][j][1] = (GLubyte) c;
            checkImage[i][j][2] = (GLubyte) c;
            checkImage[i][j][3] = (GLubyte) 255;
        }
    }
}

void loadTexture() {
    makeCheckImage();
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void drawTexturedSquare() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-0.5, -0.5);
    glTexCoord2f(1.0, 0.0); glVertex2f(0.5, -0.5);
    glTexCoord2f(1.0, 1.0); glVertex2f(0.5, 0.5);
    glTexCoord2f(0.0, 1.0); glVertex2f(-0.5, 0.5);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void display_tema4_square() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawTexturedSquare();
    glutSwapBuffers();
}

void run_tema4_square() {
    int argc = 1;
    char* argv[1] = {(char*)"Tema4_Square"};
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tema 4 Textured Square");
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    loadTexture();
    glutDisplayFunc(display_tema4_square);
    glutMainLoop();
}

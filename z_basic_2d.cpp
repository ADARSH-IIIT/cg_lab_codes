#include <GL/glut.h>
#include <cmath>

// Initialize OpenGL
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glOrtho(-10, 10, -10, 10, -1, 1);     // Set coordinate system
}

// Function to draw a triangle (wireframe)
void drawTriangleWire(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

// Function to draw a triangle (solid)
void drawTriangleSolid(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

// Function to draw a rectangle (wireframe)
void drawRectangleWire(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

// Function to draw a rectangle (solid)
void drawRectangleSolid(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

// Function to draw a line
void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// Function to draw a circle (wireframe)
void drawCircleWire(float x, float y, float radius) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159f / 180.0f; // Convert degrees to radians
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
}

// Function to draw a circle (solid)
void drawCircleSolid(float x, float y, float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159f / 180.0f; // Convert degrees to radians
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
}

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set colors and draw shapes

    // Triangle
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    drawTriangleSolid(-8, 6, -6, 8, -4, 6); // Solid triangle
    glColor3f(1.0f, 1.0f, 1.0f); // White
    drawTriangleWire(-8, 2, -6, 4, -4, 2); // Wireframe triangle

    // Rectangle
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    drawRectangleSolid(-3, 6, -1, 8); // Solid rectangle
    glColor3f(1.0f, 1.0f, 1.0f); // White
    drawRectangleWire(-3, 2, -1, 4); // Wireframe rectangle

    // Line
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    drawLine(2, 6, 6, 8); // Line

    // Circle
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    drawCircleSolid(4, 2, 2); // Solid circle
    glColor3f(1.0f, 1.0f, 1.0f); // White
    drawCircleWire(4, -2, 2); // Wireframe circle

    glFlush();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Basic Shapes - Wireframe and Solid");

    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

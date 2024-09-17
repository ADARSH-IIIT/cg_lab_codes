
#include <GL/glut.h>
#include <cmath>  // For math operations
#include <iostream>

// Function to plot a point with specific color
void plotPoint(float x, float y, float r, float g, float b) {
    // Set the color for the point
    glColor3f(r, g, b);

    // Begin drawing points
    glBegin(GL_POINTS);
    glVertex2f(x, y); // Specify the point
    glEnd();
}

// Display function to render the scene
void display() {
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Plot a point at (10, 10) with color red
    plotPoint(10.0f, 10.0f, 1.0f, 0.0f, 0.0f); // Red color

    // Plot another point at (-10, -10) with color blue
    plotPoint(-10.0f, -10.0f, 0.0f, 0.0f, 1.0f); // Blue color

    // Flush the drawing routines to the window
    glFlush();
}

// Function to initialize the rendering environment
void init() {
    // Set the background color to white
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Set up the projection matrix for 2D
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

    // Set up the model view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(512, 512);
    glutCreateWindow("Point Plotting Example");

    // Initialize rendering settings
    init();

    // Register display callback function
    glutDisplayFunc(display);

    // Enter the event processing loop
    glutMainLoop();

    return 0;
}

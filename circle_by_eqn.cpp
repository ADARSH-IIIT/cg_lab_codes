#include <GL/glut.h>
#include <cmath>  // For sqrt and fabs

// Function to plot a circle given center (cx, cy) and radius r
void plotCircle(float cx, float cy, float r) {
    // Set the color for the circle
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color

    glBegin(GL_POINTS); // Begin drawing points
    for (float x = cx - r; x <= cx + r; x += 0.1f) { // Increment x
        float dx = x - cx; // Difference from center
        float y2 = r * r - dx * dx; // Compute y squared

        if (y2 >= 0) { // Ensure the value inside sqrt is non-negative
            float yOffset = sqrt(y2); // Compute positive y offset
            glVertex2f(x, cy + yOffset); // Plot the positive y value
            glVertex2f(x, cy - yOffset); // Plot the negative y value
        }
    }
    glEnd();
}

// Display function to render the scene
void display() {
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a circle with center at (0, 0) and radius 50
    plotCircle(30.0f, 0.0f, 50.0f);

    // Flush the drawing routines to the window
    glFlush();
}

// Function to initialize the rendering environment
void init() {
    // Set the background color to white
    glClearColor(1.0, 1.0, 1.0, 1.0);

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
    glutCreateWindow("Circle Plotting Example");

    // Initialize rendering settings
    init();

    // Register display callback function
    glutDisplayFunc(display);

    // Enter the event processing loop
    glutMainLoop();

    return 0;
}

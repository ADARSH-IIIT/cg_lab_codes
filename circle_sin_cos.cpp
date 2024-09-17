#include <GL/glut.h>
#include <cmath>  // For mathematical functions

// Function to plot a circle given center (cx, cy) and radius r
void plotCircle(float cx, float cy, float r) {
    const int num_segments = 100; // Number of segments to approximate the circle
    const float angle_increment = 2.0f * M_PI / num_segments;

    glBegin(GL_LINE_LOOP); // Draw a loop of connected lines
    for (int i = 0; i < num_segments; ++i) {
        float angle = i * angle_increment;
        float x = cx + r * cos(angle); // X coordinate on the circle
        float y = cy + r * sin(angle); // Y coordinate on the circle

        glVertex2f(x, y); // Specify the point on the circumference
    }
    glEnd();
}

// Display function to render the scene
void display() {
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the color to blue
    glColor3f(0.0f, 0.0f, 1.0f);

    // Draw a circle with center at (0, 0) and radius 50
    plotCircle(30.0f, 4.0f, 50.0f);

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

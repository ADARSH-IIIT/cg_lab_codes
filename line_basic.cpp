#include <GL/glut.h>
#include <cmath>  // For fabs()
#include <iostream>

// Function to implement the line drawing algorithm
void drawLine(float x1, float y1, float x2, float y2) {
    glColor3f(1.0f, 1.0f, 1.0f); // Set the color to white

    float dx = x2 - x1;
    float dy = y2 - y1;

    if (fabs(dx) >= fabs(dy)) {
        // |m| <= 1
        float m = dy / dx;
        float c = y1 - m * x1;

        // Determine step size based on dx
        int steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
        float xIncrement = dx / steps;

        float x = x1;
        float y = m * x + c; // Initial y based on x1

        glBegin(GL_POINTS);
        for (int i = 0; i <= steps; ++i) {
            glVertex2f(x, y); // Plot the point
            x += xIncrement;
            y = m * x + c; // Calculate the new y
        }
        glEnd();
    } else {
        // |m| > 1
        float m = dx / dy;
        float c = x1 - m * y1;

        // Determine step size based on dy
        int steps = fabs(dy) > fabs(dx) ? fabs(dy) : fabs(dx);
        float yIncrement = dy / steps;

        float y = y1;
        float x = m * y + c; // Initial x based on y1

        glBegin(GL_POINTS);
        for (int i = 0; i <= steps; ++i) {
            glVertex2f(x, y); // Plot the point
            y += yIncrement;
            x = m * y + c; // Calculate the new x
        }
        glEnd();
    }
}

void drawFig2a() {
    // Set the colors and draw the lines for the "A" shape
    // Color: Black
    glColor3f(1.0f, 0.0f, 0.0f );
    drawLine(-50, -50, 0, 50);   // Line P1 -> P3 (left leg of "A")
    drawLine(0, 50, 50, -50);    // Line P3 -> P5 (right leg of "A")

    // Color: Orange (for horizontal line)
    glColor3f(1.0f, 0.5f, 0.0f);
    drawLine(-25, 0, 25, 0);     // Line P2 -> P4 (horizontal crossbar of "A")
    
    // Color: Green (optional if needed to distinguish any other line)
    glColor3f(0.0f, 1.0f, 0.0f);
    drawLine(-50, -50, 50, -50); // Line P1 -> P5 (base line)
}

// Function to display the figure
void display() {
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Fig 2a ("A" shape)
    drawFig2a();

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
    glutCreateWindow("Line Drawing Algorithm: Fig 2a - A Shape");

    // Initialize rendering settings
    init();

    // Register display callback function
    glutDisplayFunc(display);

    // Enter the event processing loop
    glutMainLoop();

    return 0;
}


// fabs ===> absolute value of double numbers 
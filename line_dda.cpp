#include <GL/glut.h>
#include <cmath>  // For abs()
#include<iostream>
// Function to implement the DDA Line Drawing Algorithm
void DDA(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    // Steps to determine how many points to plot
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    // Increment in x and y for each step
    float Xinc = dx / steps;
    float Yinc = dy / steps;

    // Start plotting points
    float X = x1;
    float Y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        glVertex2f(X, Y); // Plot the point
        X += Xinc;        // Increment X
        Y += Yinc;        // Increment Y

        std::cout << X << '\t' << Y << '\n' ;
    }
    glEnd();
}

void drawFig2a()
{
    // Set the colors and draw the lines for the "A" shape
    // Color: Black
    glColor3f(0.0f, 0.0f, 0.0f);
    DDA(-50, -50, 0, 50);   // Line P1 -> P3 (left leg of "A")
    DDA(0, 50, 50, -50);    // Line P3 -> P5 (right leg of "A")
    
    // Color: Orange (for horizontal line)
    glColor3f(1.0f, 0.5f, 0.0f);
    DDA(-25, 0, 25, 0);     // Line P2 -> P4 (horizontal crossbar of "A")
    
    // Color: Green (optional if needed to distinguish any other line)
    glColor3f(0.0f, 1.0f, 0.0f);
    // DDA(-50, -50, 50, -50); // Line P1 -> P5 (base line)
}

// Function to display the figure
void display()
{
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Fig 2a ("A" shape)
    drawFig2a();

    // Flush the drawing routines to the window
    glFlush();
}

// Function to initialize the rendering environment
void init()
{
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

int main(int argc, char** argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(512, 512);
    glutCreateWindow("DDA Line Algorithm: Fig 2a - A Shape");

    // Initialize rendering settings
    init();

    // Register display callback function
    glutDisplayFunc(display);

    // Enter the event processing loop
    glutMainLoop();

    return 0;
}
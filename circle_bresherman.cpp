#include <GL/glut.h>
#include <cmath>

// Center and radius of the circle
int centerX = 0, centerY = 0, radius = 100;

// Function to plot a point and its symmetrical points
void plotCirclePoints(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(centerX + x, centerY + y);
    glVertex2i(centerX - x, centerY + y);
    glVertex2i(centerX + x, centerY - y);
    glVertex2i(centerX - x, centerY - y);
    glVertex2i(centerX + y, centerY + x);
    glVertex2i(centerX - y, centerY + x);
    glVertex2i(centerX + y, centerY - x);
    glVertex2i(centerX - y, centerY - x);
    glEnd();
}

// Bresenham's circle drawing algorithm
void drawCircle() {
    int x = 0;
    int y = radius;
    int p = 3 - 2 * radius;

    plotCirclePoints(x, y);

    while (x <= y) {
        x++;
        if (p < 0) {
            p += 4 * x + 6;
        } else {
            y--;
            p += 4 * (x - y) + 10;
        }
        plotCirclePoints(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPointSize(2.0); // Set the point size for better visibility
    drawCircle();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-150, 150, -150, 150); // Adjust the orthographic view to fit the circle
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Circle Drawing");

    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the background color to white
    glColor3f(0.0, 0.0, 0.0); // Set the drawing color to black

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}

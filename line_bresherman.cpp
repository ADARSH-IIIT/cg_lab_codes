#include <GL/glut.h>
#include <cmath>
#include <string>

// Define points
struct Point {
    int x, y;
    const char* label;
};

Point points[] = {
    {100, 100, "p1"},
    {200, 300, "p2"},
    {300, 500, "p3"},
    {400, 300, "p4"},
    {500, 100, "p5"}
};

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresehamlinedrawing(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        drawPixel(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void drawText(const char* text, int x, int y) {
    glRasterPos2i(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the shape
    glColor3f(1.0, 1.0, 1.0);
    bresehamlinedrawing(points[0].x, points[0].y, points[1].x, points[1].y);
    bresehamlinedrawing(points[1].x, points[1].y, points[2].x, points[2].y);
    bresehamlinedrawing(points[2].x, points[2].y, points[3].x, points[3].y);
    bresehamlinedrawing(points[3].x, points[3].y, points[4].x, points[4].y);
    bresehamlinedrawing(points[1].x, points[1].y, points[3].x, points[3].y);
    bresehamlinedrawing(points[0].x, points[0].y, points[4].x, points[4].y);

    // Draw labels
    glColor3f(1.0, 0.0, 0.0);  // Red color for labels
    for (const auto& point : points) {
        drawText(point.label, point.x - 10, point.y - 20);
    }

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 600, 0, 600, -1, 1);  // Adjusted for the shape's dimensions
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Line Algorithm - Fig. 1b");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

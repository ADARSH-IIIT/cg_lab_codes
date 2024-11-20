#include <GL/glut.h>
#include <vector>
#include <string>
#include <cmath>

// Structure to hold 2D points
struct Point {
    float x, y;
    Point(float _x = 0, float _y = 0) : x(_x), y(_y) {}
};

// Store control points for all curves
std::vector<std::vector<Point>> curves = {
    // Curve (a)
    {{-0.8, 0.0}, {-0.8, 0.4}, {-0.4, 0.0}},
    // Curve (b)
    {{-0.3, 0.0}, {-0.3, 0.3}, {0.0, 0.3}, {0.0, 0.0}},
    // Curve (c)
    {{0.1, 0.0}, {0.1, 0.3}, {0.4, 0.0}, {0.4, 0.2}},
    // Curve (d)
    {{-0.8, -0.4}, {-0.4, -0.2}, {-0.6, -0.6}, {-0.4, -0.4}},
    // Curve (e)
    {{-0.2, -0.4}, {0.0, -0.2}, {0.2, -0.6}, {0.4, -0.4}}
};

// Function to display a label at a given point
void displayLabel(const Point& p, const std::string& label) {
    glRasterPos2f(p.x + 0.02f, p.y + 0.02f); // Position slightly offset for visibility
    for (char c : label) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c); // Draw each character
    }
}

// Function to compute point on Bezier curve
Point computeBezierPoint(const std::vector<Point>& controlPoints, float t) {
    int n = controlPoints.size() - 1;
    Point result(0, 0);
    
    for (int i = 0; i <= n; i++) {
        float basis = 1.0;
        // Compute Bernstein basis polynomial
        for (int j = 0; j < i; j++)
            basis *= t;
        for (int j = 0; j < n - i; j++)
            basis *= (1 - t);
            
        // Apply binomial coefficient
        int coeff = 1;
        for (int j = 0; j < i; j++)
            coeff = coeff * (n - j) / (j + 1);
            
        result.x += basis * coeff * controlPoints[i].x;
        result.y += basis * coeff * controlPoints[i].y;
    }
    
    return result;
}

// Function to draw control points, labels, and connecting lines
void drawControlPoints(const std::vector<Point>& points, int curveIndex) {
    // Draw control points
    glColor3f(0.0, 1.0, 0.0);  // Green color for control points
    glPointSize(5.0);
    glBegin(GL_POINTS);
    for (const auto& p : points) {
        glVertex2f(p.x, p.y);
    }
    glEnd();
    
    // Draw connecting lines between control points
    glColor3f(1.0, 0.0, 0.0);  // Red color for lines
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);  // Dashed line pattern
    glBegin(GL_LINE_STRIP);
    for (const auto& p : points) {
        glVertex2f(p.x, p.y);
    }
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    // Label the control points as p1, p2, ...
    for (size_t i = 0; i < points.size(); ++i) {
        std::string label = "p" + std::to_string(curveIndex + 1) + std::to_string(i + 1); // p11, p12, etc.
        displayLabel(points[i], label);
    }
}

// Function to draw a single Bezier curve
void drawBezierCurve(const std::vector<Point>& controlPoints, int curveIndex) {
    drawControlPoints(controlPoints, curveIndex);
    
    // Draw the actual curve
    glColor3f(0.0, 0.0, 0.0);  // Black color for curve
    glBegin(GL_LINE_STRIP);
    for (float t = 0; t <= 1.0; t += 0.01) {
        Point p = computeBezierPoint(controlPoints, t);
        glVertex2f(p.x, p.y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw all curves with indexed labels
    for (size_t i = 0; i < curves.size(); ++i) {
        drawBezierCurve(curves[i], i);
    }
    
    glutSwapBuffers();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bezier Curves with Labeled Control Points");
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
#include <GL/glut.h>

// Initialize OpenGL
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glEnable(GL_DEPTH_TEST);             // Enable depth testing
    glEnable(GL_LIGHTING);               // Enable lighting
    glEnable(GL_LIGHT0);                 // Enable light #0
    glEnable(GL_COLOR_MATERIAL);         // Enable color for material
    glShadeModel(GL_SMOOTH);             // Smooth shading
}

// Function to draw a sphere
void drawSphere(float radius, int slices, int stacks) {
    glColor3f(0.5f, 0.5f, 0.5f); // Grey color
    glutSolidSphere(radius, slices, stacks);
}

// Function to draw a cone
void drawCone(float base, float height, int slices, int stacks) {
    glColor3f(1.0f, 0.5f, 0.0f); // Orange color
    glutSolidCone(base, height, slices, stacks);
}

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

    glLoadIdentity();              // Reset transformations
    glTranslatef(0.0f, 0.0f, -10.0f); // Move the camera back to view the objects

    // Set up lighting position
    GLfloat lightPos[] = {0.0f, 0.0f, 2.0f, 1.0f}; // Light source position
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    // Draw the sphere
    glPushMatrix();
    glTranslatef(-3.0f, 0.0f, 0.0f); // Move sphere to the left
    drawSphere(1.0, 50, 50);
    glPopMatrix();

    // Draw the cone
    glPushMatrix();
    glTranslatef(3.0f, 0.0f, 0.0f); // Move cone to the right
    drawCone(1.0, 2.0, 50, 50);
    glPopMatrix();

    glutSwapBuffers(); // Swap the front and back buffers
}

// Resize callback for adjusting the viewport and projection
void reshape(int width, int height) {
    if (height == 0) height = 1; // Prevent divide by zero
    float aspect = (float)width / (float)height;

    glViewport(0, 0, width, height); // Set the viewport to cover the new window

    // Set the perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 1.0, 100.0); // Field of view, aspect ratio, near, far

    glMatrixMode(GL_MODELVIEW); // Switch back to model view
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Sphere and Cone");

    initGL();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

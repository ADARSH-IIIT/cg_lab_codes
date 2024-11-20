#include <GL/glut.h>

float cubeAngle = 0.0f;
float pyramidAngle = 0.0f;

void init() {
    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawCube() {
    glBegin(GL_QUADS);

    // Front face (red)
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);

    // Back face (green)
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);

    // Top face (blue)
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);

    // Bottom face (yellow)
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);

    // Right face (cyan)
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);

    // Left face (magenta)
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);

    glEnd();
}

void drawPyramid() {
    glBegin(GL_TRIANGLES);

    // Front face (red)
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);

    // Right face (green)
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, -0.5);

    // Back face (blue)
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);

    // Left face (yellow)
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5, 0.5);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Position the camera
    gluLookAt(0.0, 0.0, 5.0, // Camera position
              0.0, 0.0, 0.0, // Look at point
              0.0, 1.0, 0.0); // Up direction

    // Draw rotating Cube
    glPushMatrix();
    glTranslatef(-1.5, 0.0, 0.0); // Position the cube to the left
    glRotatef(cubeAngle, 1.0, 1.0, 1.0); // Rotate around x, y, z axis
    drawCube();
    glPopMatrix();

    // Draw rotating Pyramid
    glPushMatrix();
    glTranslatef(1.5, 0.0, 0.0); // Position the pyramid to the right
    glRotatef(pyramidAngle, 1.0, 1.0, 0.0); // Rotate around x and y axis
    drawPyramid();
    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {
    cubeAngle += 2.0f; // Update cube rotation angle
    if (cubeAngle > 360) {
        cubeAngle -= 360;
    }

    pyramidAngle += 3.0f; // Update pyramid rotation angle
    if (pyramidAngle > 360) {
        pyramidAngle -= 360;
    }

    glutPostRedisplay(); // Request display update
    glutTimerFunc(16, update, 0); // Call update function every 16 ms (~60 FPS)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rotating 3D Cube and Pyramid");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, update, 0); // Start timer
    glutMainLoop();

    return 0;
}
#include <GL/glut.h>
#include <GL/glu.h>

GLUquadric* quad;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 100.0);  // Set up perspective projection
    quad = gluNewQuadric(); // Initialize a quadric object for drawing surfaces
    gluQuadricDrawStyle(quad, GLU_LINE); // Set the quadric object to wireframe mode
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);  // Camera setup

    // Draw Sphere
    glPushMatrix();
    glTranslatef(-4.0, 0.0, 0.0);
    glutWireSphere(1.0, 8, 8); // Radius, slices, stacks for a wireframe sphere
    glPopMatrix();

    // Draw Cone
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(-70, 1.0, 0.0, 0.0); 
    glutWireCone(1.0, 2.0, 8, 8); // Base radius, height, slices, stacks for wireframe cone
    glPopMatrix();

    // Draw Cylinder using GLUquadric
    glPushMatrix();
    glTranslatef(4.0, 0.0, 0.0);
    glRotatef(-100, 1.0, 0.0, 0.0); // Rotate for correct cylinder orientation
    gluCylinder(quad, 1.0, 1.0, 2.0, 8, 8); // Base radius, top radius, height, slices, stacks
    glPopMatrix();

    glutSwapBuffers(); // Swap buffers for smooth rendering
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);  // Update perspective based on window size
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Quadric Surfaces Example");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
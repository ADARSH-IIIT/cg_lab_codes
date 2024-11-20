#include <GL/glut.h>

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 100.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Draw Tetrahedron
    glPushMatrix();
    glTranslatef(-4.0, 2.0, 0.0);
    glutWireTetrahedron();
    glPopMatrix();

    // Draw Hexahedron (Cube)
    glPushMatrix();
    glTranslatef(-2.0, -2.0, 0.0);
    glutWireCube(1.5);
    glPopMatrix();

    // Draw Octahedron
    glPushMatrix();
    glTranslatef(0.0, 2.0, 0.0);
    glutWireOctahedron();
    glPopMatrix();

    // Draw Dodecahedron
    glPushMatrix();
    glTranslatef(2.0, -1.0, 0.0);
    glutWireDodecahedron();
    glPopMatrix();

    // Draw Icosahedron
    glPushMatrix();
    glTranslatef(4.0, 1.0, 0.0);
    glutWireIcosahedron();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Polyhedra Example");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
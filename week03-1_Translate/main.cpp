#include <GL/freeglut.h>
void display()
{
    glPushMatrix();///備份矩陣
        glTranslated(0.5,0.5,0);///會改變矩陣
        glutSolidTeapot( 0.3);
    glPushMatrix();///還原矩陣
    glutSwapBuffers();
}
int main(int argc,char *argv[])
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03");

	glutDisplayFunc(display);

	glutMainLoop();
}

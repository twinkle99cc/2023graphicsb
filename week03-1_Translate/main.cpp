#include <GL/freeglut.h>
void display()
{
    glPushMatrix();///�ƥ��x�}
        glTranslated(0.5,0.5,0);///�|���ܯx�}
        glutSolidTeapot( 0.3);
    glPushMatrix();///�٭�x�}
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

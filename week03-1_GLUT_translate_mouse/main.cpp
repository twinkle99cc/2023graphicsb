#include <GL/freeglut.h>
float X=0,Y=0,Z=0;///�ϥ�global�ܼ�
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///�M�I��
    glPushMatrix();///�ƥ��x�}
        glTranslated(X,Y,Z);///�|���ܯx�}
        glutSolidTeapot( 0.3);
    glPushMatrix();///�٭�x�}

    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{       ///�����k��   ///���U/��}
    X=(x-150)/150.0;
    Y=-(y-150)/150.0;
}
int main(int argc,char *argv[])
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03");

    glutMouseFunc(mouse);
	glutDisplayFunc(display);

	glutMainLoop();
}

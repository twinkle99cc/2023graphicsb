#include <GL/freeglut.h>
void display()
{
    glColor3f(1,1,0);///��m ����
    glutSolidTeapot(0.3);

    glColor3f(0,1,0);
    glutSolidTeapot( 0.3);

    glutSwapBuffers(); ///�洫��ܥX��
}
int main(int argc,char *argv[])
{
	glutInit(&argc, argv);///�n�}�lGLUT���\��
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	///�n�]�wGLUT����ܼҦ�
    glutCreateWindow("week02");///�ؤ@�ӵ���,�s"..."
	glutDisplayFunc(display);///�n��ܪ��禡

	glutMainLoop();///�̫�n��glutMainLoop(),���b�j��᭱
}

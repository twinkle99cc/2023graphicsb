#include <GL/freeglut.h>
float X=0,Y=0,Z=0;///使用global變數
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///清背景
    glPushMatrix();///備份矩陣
        glTranslated(X,Y,Z);///會改變矩陣
        glutSolidTeapot( 0.3);
    glPushMatrix();///還原矩陣

    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{       ///左中右鍵   ///按下/放開
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

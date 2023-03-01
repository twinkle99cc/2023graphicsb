#include <GL/freeglut.h>
void display()
{
    glColor3f(1,1,0);///色彩 黃色
    glutSolidTeapot(0.3);

    glColor3f(0,1,0);
    glutSolidTeapot( 0.3);

    glutSwapBuffers(); ///交換顯示出來
}
int main(int argc,char *argv[])
{
	glutInit(&argc, argv);///要開始GLUT的功能
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	///要設定GLUT的顯示模式
    glutCreateWindow("week02");///建一個視窗,叫"..."
	glutDisplayFunc(display);///要顯示的函式

	glutMainLoop();///最後要有glutMainLoop(),壓在迴圈後面
}

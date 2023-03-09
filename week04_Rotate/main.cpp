#include <GL/freeglut.h>
float angle=0; ///全域變數 angle 角度
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清畫面
    glPushMatrix(); ///備份矩陣
        glRotatef(angle,0,1,0);///傳angle度
        glutSolidTeapot( 0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
    angle++;///角度++
}
int main(int argc,char *argv[])
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04");

	glutDisplayFunc(display);
	glutIdleFunc(display); ///重畫畫面
	glutMainLoop();
}

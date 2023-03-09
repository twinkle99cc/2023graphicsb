#include <GL/freeglut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(0.5,0,0);///移到右邊的
        glRotatef(angle,0,1,0);///旋轉中的
        glColor3f(0,0,1);///藍色的
        glutSolidTeapot( 0.3);///茶壺
    glPopMatrix();

    glPushMatrix();
        glRotatef(angle,0,1,0);///旋轉中的
        glTranslatef(0.5,0,0);///移到右邊的
        glColor3f(1,1,0);///黃色的
        glTranslatef(0,0.5,0);///移到上面的
        glutSolidTeapot( 0.3);///茶壺
    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
int main(int argc,char *argv[])
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04");

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
}

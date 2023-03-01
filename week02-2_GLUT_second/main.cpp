#include <GL/glut.h>
void display()
{
    glColor3f(0,1,0);///綠色
    glBegin(GL_POLYGON);
         glColor3f(1,0,0);glVertex2f(0,1);///紅色 上面
         glColor3f(0,1,0);glVertex2f(-1,-1);///綠色 左下角
         glColor3f(0,0,1);glVertex2f(+1,-1);///藍色 右下角
    glEnd();

    glColor3f(1,1,0);///黃色
    glutSolidTeapot( 0.5 );///大茶壺

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutCreateWindow("GLUT Shapes");
glutDisplayFunc(display);
glutMainLoop();
}

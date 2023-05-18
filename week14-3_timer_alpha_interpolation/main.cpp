///week14-3_timer_alpha_interpolation
#include <GL/glut.h>
float angle = 0, newAngle = 0, oldAngle = 0;///step02-2 �ŧi �s���סB�¨���
float oldX = 0;///step02-2 �ª�x�y��
void timer(int t)
{
    if(t<100) glutTimerFunc(33,timer,t+1);
    float alpha = t/100.0;///step02-2 �ҥHalpha����0.0~1.0����
    angle = alpha*newAngle + (1-alpha)*oldAngle;///step02-2
    glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y)
{
    glutTimerFunc(0,timer,0);
}
void mouse(int button,int state,int x,int y){
    if(state==GLUT_DOWN) oldAngle = angle;///step02-2
    if(state==GLUT_UP) newAngle = angle;///step02-2
    oldX = x;///step02-2
    glutPostRedisplay();///step02-2��s�e��
}
void motion(int x,int y){
    angle += x-oldX;///step02-2
    oldX = x;///step02-2
    glutPostRedisplay();///step02-2��s�e��
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14");

    glutMouseFunc(mouse);///step02-2
    glutMotionFunc(motion);///step02-2
    glutKeyboardFunc(keyboard);///step01-2
    ///glutTimerFunc(3000,timer,0);///step01-1
    glutDisplayFunc(display);

    glutMainLoop();
}

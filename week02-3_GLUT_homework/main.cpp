#include <GL/freeglut.h>
void display()
{
    glBegin(GL_POLYGON);
    glColor3f(0,0,1);glVertex2f((100-100)/100.0,-(3-100)/100.0);
    glColor3f(0,0,1);glVertex2f((130-100)/100.0,-(7-100)/100.0);
    glColor3f(0,0,1);glVertex2f((157-100)/100.0,-(21-100)/100.0);
    glColor3f(0,0,1);glVertex2f((178-100)/100.0,-(43-100)/100.0);
    glColor3f(0,0,1);glVertex2f((190-100)/100.0,-(70-100)/100.0);
    glColor3f(0,0,1);glVertex2f((196-100)/100.0,-(99-100)/100.0);
    glColor3f(0,0,1);glVertex2f((192-100)/100.0,-(130-100)/100.0);
    glColor3f(0,0,1);glVertex2f((178-100)/100.0,-(156-100)/100.0);
    glColor3f(0,0,1);glVertex2f((156-100)/100.0,-(179-100)/100.0);
    glColor3f(0,0,1);glVertex2f((129-100)/100.0,-(192-100)/100.0);
    glColor3f(0,0,1);glVertex2f((100-100)/100.0,-(197-100)/100.0);
    glColor3f(0,0,1);glVertex2f((69-100)/100.0,-(191-100)/100.0);
    glColor3f(0,0,1);glVertex2f((43-100)/100.0,-(178-100)/100.0);
    glColor3f(0,0,1);glVertex2f((22-100)/100.0,-(157-100)/100.0);
    glColor3f(0,0,1);glVertex2f((70-100)/100.0,-(7-100)/100.0);
    glColor3f(0,0,1);glVertex2f((43-100)/100.0,-(22-100)/100.0);
    glColor3f(0,0,1);glVertex2f((21-100)/100.0,-(43-100)/100.0);
    glColor3f(0,0,1);glVertex2f((8-100)/100.0,-(71-100)/100.0);
    glColor3f(0,0,1);glVertex2f((2-100)/100.0,-(100-100)/100.0);
    glColor3f(0,0,1);glVertex2f((8-100)/100.0,-(130-100)/100.0);
    glColor3f(0,0,1);glVertex2f((21-100)/100.0,-(156-100)/100.0);
    glEnd();

    glutSwapBuffers();
}
int main(int argc,char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week02");
    glutDisplayFunc(display);

    glutMainLoop();
}

///Week12-4_keyboard_mouse �n��� mouse�Ӳ���, �P�ɭn�ѨM�sŪ�ɪ����D
#include <stdio.h> ///�n�ɮת�Input/Output
#include <GL/glut.h>
float teapotX = 0, teapotY = 0;
FILE * fout = NULL;///step02-1
FILE * fin = NULL;///step02-2
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
    teapotX = (x-150)/150.0;
    teapotY = (150-y)/150.0;
    if(state==GLUT_DOWN){ ///�p�Gmouse���U�h
        if(fout==NULL) fout = fopen("file4.txt", "w");

        fprintf(fout, "%f %f\n", teapotX, teapotY);
    }
    display();
}
void keyboard(unsigned char key, int x, int y)///step02-2
{
    if(fin==NULL){
        fclose(fout);///step02-2
        fin = fopen("file4.txt", "r");///step02-2
    }
    fscanf(fin, "%f%f", &teapotX, &teapotY);///step02-2
    display();///step02-2
}///step02-2
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); ///step02-2
    glutMouseFunc(mouse); ///step02-1

    glutMainLoop();
}

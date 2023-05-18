///Final_Project 之後都用同一個程式,來進行 Final Project
#include <stdio.h> ///要檔案的Input/Output
#include <GL/glut.h>
#include "glm.h" ///week13_step02-2
///week13_step02-2 再把 glm.cpp 在左邊 Add files 加進去
GLMmodel * head = NULL;///week13_step02-2
GLMmodel * body = NULL;///week13_step02-2
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4] = {1,0,0,0}; ///week13_step03-1
float teapotX = 0, teapotY = 0;
FILE * fout = NULL;///step02-1
FILE * fin = NULL;///step02-2
void keyboard(unsigned char key, int x, int y) {///week13_step03-1
    if(key=='0') show[0] = ! show[0];///week13_step03-1
    if(key=='1') show[1] = ! show[1];///week13_step03-1
    if(key=='2') show[2] = ! show[2];///week13_step03-1
    if(key=='3') show[3] = ! show[3];///week13_step03-1
    glutPostRedisplay();///week13_step03-1
}///week13_step03-1
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(head==NULL){///week13_step02-2
        head = glmReadOBJ("model/head.obj");///week13_step02-2
        body = glmReadOBJ("model/body.obj");
        uparmR = glmReadOBJ("model/uparmR.obj");
        lowarmR = glmReadOBJ("model/lowarmR.obj");
        ///glmUnitize(head); ///week13_step02-2 之後會改
    }///week13_step02-2
    glPushMatrix();
        glScalef(0.3, 0.3, 0.3);///week13_step02-3
        glPushMatrix();///week13_step03-2
            glTranslatef(teapotX, teapotY, 0); ///week13_step03-2
            if(show[0]) glmDraw(head, GLM_MATERIAL);///week13_step02-3
        glPopMatrix();///week13_step03-2
        if(show[1]) glmDraw(body, GLM_MATERIAL);///week13_step02-2
        if(show[2]) glmDraw(uparmR, GLM_MATERIAL);///week13_step02-3
        if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);///week13_step02-3
        ///week13_step03-1 加上 if(show[??]) ...
    glPopMatrix();
    glutSwapBuffers();
}
int oldX=0, oldY=0; ///week13_step03-2
void mouse(int button, int state, int x, int y) {
    if(state==GLUT_DOWN){
        oldX = x;
        oldY = y;
    }
}
void motion(int x, int y) { ///week13_step03-2
    teapotX += (x - oldX)/150.0*3;
    teapotY -= (y - oldY)/150.0*3;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutMotionFunc(motion); ///week13_step03-2
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();
}

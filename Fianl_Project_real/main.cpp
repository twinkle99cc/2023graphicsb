#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
GLMmodel * armr = NULL, * arml = NULL;
GLMmodel * handr = NULL,* handl = NULL;
float teapotX = 0, teapotY = 0, angle = 0, angle2 = 0, oldX = 0, oldY = 0;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}
void motion(int x, int y) {
    teapotX += (x - oldX) / 150.0 * 2; ///teapotX = (x-150)/150.0;
    teapotY += (oldY - y) / 150.0 * 2; ///teapotY = (150-y)/150.0;
    angle += x - oldX;
    angle2 += y - oldY;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
    printf("  glTranslatef( %.2f, %.2f, 0 ); \n", teapotX, teapotY );
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(1.6, 1.6, 1.6);
        glTranslatef(0, -0.3, 0);///���U�@�b
        glPushMatrix();
            glColor3f(1,1,1);
            glScalef(0.4, 0.4, 0.4);
            ///glRotatef(angle, 0, 1, 0);
            glmDraw(body, GLM_MATERIAL|GLM_TEXTURE);///glmDraw(gundam, GLM_MATERIAL|GLM_TEXTURE);
            glPushMatrix();
                ///glTranslatef(teapotX,teapotY,0);
                glTranslatef( 0.17, 1.61, 0 );
                glRotatef(angle, 0, 1, 0);
                glRotatef(angle2, 1, 0, 0);
                glTranslatef( -0.17, -1.61, 0 );
                glmDraw(armr,GLM_MATERIAL|GLM_TEXTURE);
            glPopMatrix();
            glPushMatrix();
                glTranslatef( 0.00, 1.68, 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef( 0.00, -1.68, 0 );
                glmDraw(head, GLM_MATERIAL|GLM_TEXTURE);
            glPopMatrix();
        glPopMatrix();

        glColor3f(0,1,0);
        glutSolidTeapot( 0.02 );

    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("final");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj"); ///gundam = glmReadOBJ("model/Gundam.obj");
    armr = glmReadOBJ("model/armr.obj");
    arml = glmReadOBJ("model/arml.obj");
    handr = glmReadOBJ("model/handr.obj");
    handl = glmReadOBJ("model/handl.obj");

    myTexture("model/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}

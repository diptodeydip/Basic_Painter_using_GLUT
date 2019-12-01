#include<stdio.h>
#include<GL/glut.h>

int flag=0;
double bsize=4;

void myInit (void)
{
    // Reset background color with white (since all three argument is 1.0)
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(bsize);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1200, -640, 0);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}


void keyboard(unsigned char key, int X, int Y)
{
    //Ascii of 'r'
    if(key==114){
            glPointSize(bsize);
        glColor3f(1.0f, 0.0f, 0.0f);
    }
    //Ascii of 'g'
    if(key==103){
            glPointSize(bsize);
        glColor3f(0.0f, 1.0f, 0.0f);
    }
    //Ascii of 'b'
    if(key==98){
            glPointSize(bsize);
        glColor3f(0.0f, 0.0f, 1.0f);
    }
    //Ascii of 'B'
    if(key==66){

        glPointSize(bsize);
        glColor3f(0.0f, 0.0f, 0.0f);
    }

    //Ascii of 'e'
    if(key==101){
            glPointSize(20.0);
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    //Ascii of '+'
    if(key==43){
         bsize++;
         glPointSize(bsize);
    }
    //Ascii of '-'
    if(key==45){
         bsize--;
         glPointSize(bsize);
    }
    //Ascii of 'c'
    if(key==99){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    glutPostRedisplay();

}

void myMouseFunc(int button, int state, int x, int y)
{
   if(GLUT_LEFT_BUTTON == button)flag=1;
   if(GLUT_RIGHT_BUTTON == button)flag=0;
   glutPostRedisplay();
}

void mousemotion(int x, int y)
{
    if(flag==1){
	draw_pixel(x,(-1)*y);
    }
	glutPostRedisplay();
}

void myDisplay(void)
{
        glutSwapBuffers();
}

int main (int argc, char** argv)
{
    printf("Press B to SELECT Black brush\n");
    printf("Press r to SELECT Red brush\n");
    printf("Press g to SELECT Green brush\n");
    printf("Press b to SELECT Blue brush\n");
    printf("Press c for 2 sec to CLEAR window\n");
    printf("Press + to INCREASE brush size\n");
    printf("Press - to DECREASE brush size\n");
    printf("Press e to SELECT     Eraser brush\n");
    printf("Click MOUSE LEFT BUTTON to Enable brush\n");
    printf("CLICK MOUSE RIGHT BUTTON TO Disable brush\n");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1200, 640);
    glutInitWindowPosition(600, 0);
    glutCreateWindow("Basic Painter");
    glutKeyboardFunc(keyboard);
    glutMouseFunc(myMouseFunc);
    glutPassiveMotionFunc(mousemotion);
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}

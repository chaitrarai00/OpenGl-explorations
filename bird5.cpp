#include<GL/glut.h>
#define BOX 1
float ballX = -0.3f;
float ballY = 0.0f;
float ballZ = -1.0f;
//static int flag=1;
void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}

void reshaped(int w,int h)
{
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45,(double)w/(double)h,1,200);
}

void keyPressed(int key,int x,int y)
{
      if(key==GLUT_KEY_RIGHT)
        ballX -= 0.05f;
    if(key==GLUT_KEY_LEFT)
        ballX  += 0.05f;

    glutPostRedisplay();
}


float x=0.0,y=0.0,x1=5.0;

void update()
{
    x+=0.01;
    x1-=0.02;
    if(x>6)
        {
            x=-6;
            x1=4;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   
    glMatrixMode(GL_MODELVIEW);
   
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(x1,y,-5.0);
glNewList(BOX,GL_COMPILE_AND_EXECUTE);

glBegin(GL_POLYGON);
glColor3f(1.0,0.0,1.0);
glVertex2f(-1.0,1.0);
glVertex2f(100.0,100.0);
glVertex2f(150.0,150.0);

   glEnd();

glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,1.0);
glVertex2f(-1.0,-1.0);
glVertex2f(1.0,-1.0);
glVertex2f(0.0,1.0);
   glEnd();

glEndList();
glCallList(BOX);
    glPopMatrix();

    glBegin(GL_POLYGON);
        
        glColor3f(0.0,1.0,0.0);
        
        glVertex3f(-2.0,-2.0,-5.0);
        glVertex3f(-1.0,-1.5,-5.0);
        //glVertex3f(0.0,0.0,-5.0);
        glVertex3f(2.0,-2.0,-5.0);
        glVertex3f(1.2,-1.5,-5.0);
        
    glEnd();

   
    glPushMatrix();

    glTranslatef(x,y,-5.0);

    glCallList(BOX);
    glPopMatrix();
 update();
   
    glutSwapBuffers();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
   
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
   
    glutInitWindowSize(400,400);
   
    glutCreateWindow("Simple Cloud");
   
    initRendering();
   
    glutDisplayFunc(display);
   
    glutIdleFunc(display);
   
    glutReshapeFunc(reshaped);
   
    glutSpecialFunc(keyPressed);
        
    glutMainLoop();

return(0);
}

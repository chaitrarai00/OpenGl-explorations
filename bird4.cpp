#include<GL/glut.h>
#include<stdio.h>
GLfloat count=0;
GLint i=0;
void reshaped(int w,int h)
{
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //gluPerspective(45,(double)w/(double)h,1,200);
}

void idle()
{
glutPostRedisplay();
}
void bird()
{

glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(10+i,530);
glVertex2f(10+i,570);
glVertex2f(40+i,550);
glEnd();

glBegin(GL_POLYGON);
glColor3f(1.0,1.0,0.0);
glVertex2f(30+i,550);
glVertex2f(30+i,560);
glVertex2f(100+i,550);
glEnd();
if(count<=5)
{
glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(30+i,550);
glVertex2f(60+i,510);
glVertex2f(100+i,550);
glEnd();
count++;
}
else
{
glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(30+i,550);
glVertex2f(60+i,590);
glVertex2f(100+i,550);
glEnd();
count=0;
}

glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(90+i,550);
glVertex2f(110+i,560);
glVertex2f(130+i,545);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);
glVertex2f(112+i,555);
glVertex2f(114+i,555);
glVertex2f(114+i,557);
glVertex2f(112+i,557);
glEnd();
}

void birdu()
{
glBegin(GL_TRIANGLES);
glColor3f(1.0,0.2,0.5);
glVertex2f(10+i,330);
glVertex2f(10+i,370);
glVertex2f(40+i,350);
glEnd();

glBegin(GL_POLYGON);
glColor3f(1.0,0.2,0.5);
glVertex2f(30+i,350);
glVertex2f(30+i,360);
glVertex2f(100+i,350);
glEnd();
if(count<=5)
{
glBegin(GL_TRIANGLES);
glColor3f(1.0,0.2,0.5);
glVertex2f(30+i,350);
glVertex2f(60+i,310);
glVertex2f(100+i,350);
glEnd();
count++;
}
else
{
glBegin(GL_TRIANGLES);
glColor3f(1.0,0.2,0.5);
glVertex2f(30+i,350);
glVertex2f(60+i,390);
glVertex2f(100+i,350);
glEnd();
count=0;
}
glBegin(GL_TRIANGLES);
glColor3f(1.0,0.2,0.55);
glVertex2f(90+i,350);
glVertex2f(110+i,360);
glVertex2f(130+i,345);
glEnd();


glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);
glVertex2f(112+i,355);
glVertex2f(114+i,355);
glVertex2f(114+i,357);
glVertex2f(112+i,357);
glEnd();
}


void display()
{

for(i=0;i<1100;i++)
{
glClear(GL_COLOR_BUFFER_BIT);
bird();
birdu();
glFlush();
}
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(1100,700);
glutInitWindowPosition(0,0);
glutCreateWindow("bird1");
gluOrtho2D(0.0,1100.0,0.0,700.0);
glutDisplayFunc(display);
glutIdleFunc(idle);           
glutMainLoop();
return 0;
}

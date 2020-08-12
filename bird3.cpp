#include<GL/glut.h>
#include<stdio.h>
GLfloat count=0;
void reshaped(int w,int h)
{
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45,(double)w/(double)h,1,200);
}

void idle()
{
glutPostRedisplay();
}
void bird()
{
glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(10,530);
glVertex2f(10,570);
glVertex2f(40,550);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,0.0);
glVertex2f(30,550);
glVertex2f(30,560);
glVertex2f(100,550);
glEnd();
if(count<=5)
{
glPushMatrix();
glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(30,550);
glVertex2f(60,510);
glVertex2f(100,550);
glEnd();
count++;
glPopMatrix();
}
else
{
glPushMatrix();
glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(30,550);
glVertex2f(60,590);
glVertex2f(100,550);
glEnd();
count=0;
glPopMatrix();
}
glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(90,550);
glVertex2f(110,560);
glVertex2f(130,545);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);
glVertex2f(112,555);
glVertex2f(114,555);
glVertex2f(114,557);
glVertex2f(112,557);
glEnd();
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
bird();
glFlush();
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(1000,1000);
glutInitWindowPosition(0,0);
glutCreateWindow("bird1");
gluOrtho2D(0.0,1000.0,0.0,1000.0);
glutDisplayFunc(display);
glutIdleFunc(idle);           
glutMainLoop();
return 0;
}

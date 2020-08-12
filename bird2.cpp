#include<GL/glut.h>
#include<stdio.h>
GLfloat count=0,count2=0;
GLfloat x=0,y=-0.7;
/*void initGL()
{
glClearColor(0.0, 0.0, 0.0, 1.0);
glLoadIdentity();
glPointSize(5);
glMatrixMode(GL_PROJECTION); 
gluOrtho2D(-1,1,-1,1);
}*/

void idle()
{
glutPostRedisplay();
}
void bird()
{
glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(10,30);
glVertex2f(10,70);
glVertex2f(40,50);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,0.0);
glVertex2f(30,50);
glVertex2f(30,60);
glVertex2f(100,50);
glEnd();
if(count<=7)
{
glPushMatrix();
glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(30,50);
glVertex2f(60,10);
glVertex2f(100,50);
glEnd();
count++;
glPopMatrix();
}
else
{
glPushMatrix();
glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(30,50);
glVertex2f(60,90);
glVertex2f(100,50);
glEnd();
count=0;
glPopMatrix();
}
glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(90,50);
glVertex2f(110,60);
glVertex2f(130,45);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);
glVertex2f(112,55);
glVertex2f(114,55);
glVertex2f(114,57);
glVertex2f(112,57);
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
glutInitWindowSize(400,400);
glutInitWindowPosition(0,0);
glutCreateWindow("bird1");
gluOrtho2D(0.0,400.0,0.0,400.0);
glutDisplayFunc(display);
glutIdleFunc(idle);           
glutMainLoop();
return 0;
}

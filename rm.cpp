#include<stdio.h>
#include<GL/glut.h>
#define maxx 20
#define maxy 25
#define dx 15
#define dy 10

GLfloat x[maxx]={0,0},y[maxy]={0,0};
GLfloat x0=50;
GLfloat y0=50;
GLint i,j;
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
for(i=0;i<maxx;i++)
x[i]=x0+i*dx;
for(j=0;j<maxy;j++)
y[j]=y0+j*dy;
for(i=0;i<maxx-1;i++)
for(j=0;j<maxx-1;j++)
{
glBegin(GL_LINE_LOOP);
glVertex2f(x[i],y[j]);
glVertex2f(x[i+1],y[j]);
glVertex2f(x[i+1],y[j+1]);
glVertex2f(x[i],y[j+1]);
glEnd();
glFlush();
}
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(400,500);
glutInitWindowPosition(0,0);
glutCreateWindow("mesh");
glutDisplayFunc(display);
gluOrtho2D(0.0,400,0.0,500);
glutMainLoop();
return 0;
}
